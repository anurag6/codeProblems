#include<iostream>
using namespace std;

long long spiralCornerSum(long long x){
	long long ret=0;
	if(x<1)
		ret = 0;
	else if(x==1)
		ret = 1;
	else 
		ret = 4*x*x - 6*x + 6;
	ret = ret%(1000000009);
//	console.log("spiralCornerSum("+x+"):"+ret);
	//cout<<"spiralCornerSum("<<x<<"):"<<ret<<endl;
	return ret;
}
long long evenSquares(long long x){
	//long long ret = ((2*x)%(1000000009))*((x+1)%(1000000009))*((2*x+1)%(1000000009));
	long long l1 = 2*x;
	long long l2 = x+1;
	long long l3 = 2*x+1;
	long long ret = 0;
	switch(x%3){
		case 0:
			l1 = l1/3;
			break;
		case 1:
			l3 = l3/3;
			break;
		case 2:
			l2 = l2/3;
			break;
		default:
			cout<<"EvenSquares error.";
			break;	
	}
	/*if(ret%3 != 0)
		cout<<"evenSquares error"<<endl;*/
	//cout<<"evenSquares("<<x<<"):"<<ret<<endl;
	//ret = ret/3;
	ret = (l1*l2)%(1000000009);
	ret = (ret*l3)%(1000000009);
	//cout<<"evenSquares("<<x<<"):"<<ret<<endl;
	return ret%(1000000009);
}
long long oddSquares(long long x){
	//long long ret = ((x)%(1000000009))*((2*x+1)%(1000000009))*((2*x-1)%(1000000009));
//	cout<<"oddSquares("<<x<<"):"<<ret<<endl;
	long long l1 = x;
	long long l2 = 2*x-1;
	long long l3 = 2*x+1;
	long long ret = 0;
	switch(x%3){
		case 0:
			l1 = l1/3;
			break;
		case 1:
			l3 = l3/3;
			break;
		case 2:
			l2 = l2/3;
			break;
		default:
			cout<<"oddSquares error.";
			break;	
	}
	/*if(ret%3 != 0)
		cout<<"oddSquares error"<<endl;	*/
	//ret = ret/3;
	ret = (l1*l2)%(1000000009);
	ret = (ret*l3)%(1000000009);
	//cout<<"oddSquares("<<x<<"):"<<ret<<endl;
	return ret%(1000000009);
}
long long evenSum(long long x){
	long long ret = ((x)%(1000000009))*((x+1)%(1000000009));
	//cout<<"evenSum("<<x<<"):"<<ret<<endl;
	return ret%(1000000009);
}
long long oddSum(long long x){
	long long ret = ((x)%(1000000009))*((x)%(1000000009));
	//cout<<"oddSum("<<x<<"):"<<ret<<endl;
	return ret%(1000000009);
}
/*long long diagonalSum(long long x){
	long long sum=0;
	for(int i=x;i>0;i-=2){
		sum += spiralCornerSum(i);
		sum = sum%(1000000009);
	}
	//cout<<"diagonalSum:("<<x<<")"<<sum;
	return sum;
}*/
long long diagonalSumAlt(long long x){
	long long sum=0;
	for(long long i=x;i>0;i-=2){
		long long ret=0;
		if(i<1)
			ret = 0;
		else if(i==1)
			ret = 1;
		else 
			ret = 4*i*i - 6*i + 6;
		ret = ret%(1000000009);
		//sum += spiralCornerSum(i);
		sum += ret;
		sum = sum%(1000000009);
	}
	//cout<<"diagonalSumAlt:("<<x<<")"<<sum<<endl;
	return sum;
}
long long diagonalSum(long long x){
	long long n=0;
	long long ret=0;
	if (x==1)
	{
		ret = 1;
	}
	if(x%2==0){
		n = x/2;
		ret = ((4*evenSquares(n)%(1000000009))%(1000000009))
			- ((6*evenSum(n)%(1000000009))%(1000000009)) +6*n%(1000000009);
		//cout<<((4*evenSquares(n)))<<endl<<((6*evenSum(n)))
		//	<<endl<<6*n<<endl;
	//	cout<<ret<<endl;
	}
	else{
		n = (x+1)/2;
		ret = ((4*(oddSquares(n)-1)%(1000000009))%(1000000009))
			- ((6*(oddSum(n)-1)%(1000000009))%(1000000009)) + 6*(n-1)%(1000000009) + 1;
	}
	ret = ret%(1000000009);
	//cout<<"diagonalSum("<<x<<"):"<<ret<<endl;
	if(ret<0)
		ret = 1000000009 + ret;
	return ret;
}
int main(){
	long long T=0;
	cin>>T;
	for(long long i=0;i<T;i++){
		long long inp=0;
		cin>>inp;	
		cout<<diagonalSum(inp)<<endl;
	//	cout<<diagonalSumAlt(inp)<<endl;
	}
	/*for(long long i=1;i<=10000000;i++)
	{
		if(diagonalSum(i)!=diagonalSumAlt(i)){
			cout<<"i:"<<i<<" diagonalSum:"<<diagonalSum(i)
				<<" diagonalSumAlt:"<<diagonalSumAlt(i);
			break;
		}
	}*/
	return 0;
}
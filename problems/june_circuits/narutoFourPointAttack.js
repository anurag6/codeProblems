
var sumEvenSquares = function(x){
	var ret;
	if(x<=0)
		ret = 0;
	else{
		ret = 2*x*(x+1)*(2*x+1)/3;
	}
	console.log("sumEvenSquares returning "+ret+".");
	return ret%(1000000009);
};
var sumOddSquares = function(x){
	var ret;
	if(x<=0)
		ret = 0;
	else{
		ret = x*(2*x+1)*(2*x-1)/3;
	}
	console.log("sumOddSquares returning "+ret+".");
	return ret%(1000000009);
};
var sumOdd = function(x){
	var ret;
	if(x<=0)
		ret = 0;
	else{
		ret = x*x;
	}
	console.log("sumOdd returning "+ret+".");
	return ret%(1000000009);
};
var sumEven = function(x){
	var ret;
	if(x<=0)
		ret = 0;
	else{
		ret = x*(x+1);
	}
	console.log("sumEven returning "+ret+".");
	return ret%(1000000009);
};
var diagonalSum = function(x){
	var ret=0;
	var n = 0;
	if(x==1)
		ret = 1;
	else if(x%2===0){
		n=x/2;
		ret = 4*sumEvenSquares(n)%(1000000009)
			-6*sumEven(n)%(1000000009) +6*n%(1000000009);
	}
	else {
		n=(x+1)/2
		ret = 4*(sumOddSquares(n)-1)%(1000000009)
			-6*(sumOdd(n)-1)%(1000000009) + 6*(n-1) + 1;
	}
	//console.log("diagonalSum ret:"+ret);
	return ret%(1000000009);
};
var spiralCornerSum = function(x){
	var ret;
	if(x<1)
		ret = 0;
	else if(x==1)
		ret = 1;
	else 
		ret = 4*x*x - 6*x + 6;
	ret = ret%(1000000009);
//	console.log("spiralCornerSum("+x+"):"+ret);
	return ret;
};
/*var diagonalSum = function(x){
	var sum=0;
	for(var i=x;i>0;i-=2){
		sum += spiralCornerSum(i);
		sum = sum%(1000000009);
	}
	return sum;
};*/
/*var diagonalSum = function(x){

};*/
console.log(diagonalSum(10000000));
//console.log(40);

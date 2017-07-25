#include<iostream>
using namespace std;

long long fib[15000];
long long sum[15000];

void populateFib()
{
	fib[0] = 0;
	fib[1] = 1;
	for(long long i=2;i<15000;i++)
	{
		fib[i] = (fib[i-1]+fib[i-2])%10000;
	}
}

void populateSumFib()
{
	sum[0]=0;
	for (long long i = 1; i < 15000; ++i)
	{
		sum[i] = (sum[i-1]+fib[i])%1000000007;
	}
}

long long returnFibLastFour(long long index)
{
	long long x = index%15000;
	cout<<__FUNCTION__<<" index:"<<x<<endl;
	return fib[index%15000];
}

long long returnFibLastFourSum(long long l, long long r)
{
	long long _sum = 0;
	if(l/15000 == r/15000)
	{
		l=l%15000;
		r=r%15000;
		//cout<<__FUNCTION__<<" same side of 15k."<<endl;
		_sum += sum[r] - sum[l-1];
	}
	else
	{
		long long intrm = (r-l)/15000;
		//cout<<__FUNCTION__<<" intrm:"<<intrm<<endl;
		l=l%15000;
		r=r%15000;
		_sum += sum[14999]*intrm;
		_sum += sum[14999] - sum[l-1];
		_sum += sum[r];
	}
	return _sum%1000000007;
}

int main(int argc, char const *argv[])
{
	populateFib();
	populateSumFib();
	long long T;
	cin>>T;
	long long i = 1;
	while(i<=T)
	{
		long long l,r;
		cin>>l>>r;
		cout<<returnFibLastFourSum(l-1,r-1)<<endl;
		i++;
	}
	return 0;
}
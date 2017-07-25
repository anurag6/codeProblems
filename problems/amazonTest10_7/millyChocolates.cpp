#include<iostream>
#include<map>
using namespace std;
std::map<long long, long long> mapChocolate;
std::map<long long, long long>::iterator iterLow;

//implement if you get time
std::map<long long, long long>::iterator getLowerBound(long long value)
{
	map<long long, long long>::iterator
}

map<long long, long long>::iterator binarySearch(
		map<long long, long long>::iterator left,
		map<long long, long long>::iterator right, long long value)
{
	map<long long, long long>::iterator mid = left + distance(left,right)/2;
	if(*left == value)
		return left;
	if(*mid == value)
		return mid;
	if(value < *mid)
	{
		return binarySearch();
	}
}

int main(int argc, char const *argv[])
{
	int N,Q;
	std::cin>>N;
	long long sum=1;
	for (int i = 0; i < N; ++i)
	{
		mapChocolate[sum] = i+1;
 		int x;
		std::cin>>x;
		sum += x;
	}
	/*for (iterLow = mapChocolate.begin();iterLow!=mapChocolate.end(); ++iterLow)
	{
		std::cout<<std::endl<<"["<<iterLow->first<<"]="<<iterLow->second<<std::endl;
	}*/
	std::cin>>Q;
	for (int i = 0; i < Q; ++i)
	{
		int x;
		std::cin>>x;
		iterLow=mapChocolate.upper_bound(x);
		iterLow--;
		//std::cout<<iterLow->first<<" "<<iterLow->second<<std::endl;
		std::cout<<iterLow->second<<std::endl;
	}
	return 0;
}
#include<iostream>
//#include<unordered_map>
#include<vector>
#include<cstdlib>
#include<map>
using namespace std;

map<long long, bool> visited;
map<long long, bool>::iterator _iterator;
std::vector<long long> rockets;
long long N,Q;


bool canBeReached(long long planet)
{
	_iterator = visited.find(planet);
	if (_iterator == visited.end())
	{
		for (int i = 0; i < rockets.size(); ++i)
		{
			if (planet - rockets[i] < 0)
			{
				continue;
			}
			if(canBeReached(planet - rockets[i]))
			{
				visited[planet] = true;
				return true;
			}
		}
		return false;
	}
	else
	{
		return visited[planet];
	}
}

int main(int argc, char const *argv[])
{
	visited[0] = true;
	cin>>N>>Q;
	for (long long i = 0; i < N; ++i)
	{
		long long r;
		cin>>r;
		rockets.push_back(r);
	}
	for (long long i = 0; i < Q; ++i)
	{
		long long x;
		cin>>x;
		if (canBeReached(x))
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
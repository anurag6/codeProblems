#include<iostream>
#include<vector>
using namespace std;

long long N; 		//number of people
std::vector<long long> *adjacencyList; 	//array of adjacency lists(Make it N+!)
std::vector<long long> connectedComponentCache; //holds no. of leaders for each connected component
std::vector<bool> visited;	//track all friends that have been visited
std::vector<long long> intelligence; //intelligence of each friend

void addEdge(long long u, long long v)
{
	adjacencyList[u].push_back(v);
	adjacencyList[v].push_back(u);
}

void runDFS(long long u, long long &maxIntelligence, long long &count)
{
	visited[u] = true;
	if(intelligence[u] == maxIntelligence)
	{
		count++;
	}
	else if(intelligence[u] > maxIntelligence)
	{
		maxIntelligence = intelligence[u];
		count=1;
	}

	for (vector<long long>::iterator i = adjacencyList[u].begin();i != adjacencyList[u].end(); ++i)
	{
		if(!visited[*i])
		{
			runDFS(*i,maxIntelligence,count);
		}
	}
}

void iterateThroughGraph()
{
	for (int i = 1; i <= N; ++i)
	{
		if(!visited[i])
		{
			long long _maxIntelligence = 0;
			long long _count=0;
			runDFS(i,_maxIntelligence,_count);
			if(_count>0)
			{
				//cout<<"For connected component("<<connectedComponentCache.size()<<") max:"
					//<<_maxIntelligence<<" count:"<<_count<<endl;
				connectedComponentCache.push_back(_count);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	long long M;
	cin>>N>>M;
	adjacencyList = new vector<long long>[N+1];
	visited.resize(N+1);	
	fill(visited.begin(),visited.end(),false);
	intelligence.resize(N+1);
	fill(intelligence.begin(),intelligence.end(),0);

	for (int i = 1; i <= N; ++i)
	{
		long long x;
		cin>>x;
		intelligence[i] = x;
	}

	for (int i = 0; i < M; ++i)
	{
		long long x,y;
		cin>>x>>y;
		addEdge(x,y);
	}

	iterateThroughGraph();

	//cout<<"No. of connected components:"<<connectedComponentCache.size()<<endl;
	//cout<<"Solution:"<<endl;
	long long product = 1;
	for(vector<long long>::iterator it = connectedComponentCache.begin();
			it!=connectedComponentCache.end();it++)
	{
		product = product * *it;
		product = product % (1000000007);
	}
	cout<<product<<endl;
	return 0;
}
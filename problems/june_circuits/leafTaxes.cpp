#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;


typedef pair<int,int> incTax;
std::map<int, incTax*> vertexMap;
std::vector<incTax*> totalTaxCache;
int adjacencyMatrix[501][501];
std::vector<int> cameras;

void printVertexMap()
{
	cout<<"vertexMap:"<<endl;
	for(std::map<int,incTax*>::iterator it = vertexMap.begin();
		 it != vertexMap.end();it++)
	{
		cout<<"<"<<(it->second)->first<<","<<(it->second)->second<<"> ";
	}
	cout<<endl;
}

void printtotalTaxCache()
{
	cout<<"printtotalTaxCache:"<<endl;
	for (int i = 0; i < totalTaxCache.size(); ++i)
	{
		cout<<"<"<<totalTaxCache[i]->first<<","<<totalTaxCache[i]->second<<"> ";
	}
	cout<<endl;
}

bool comparePair(incTax *a, incTax *b)
{
	return (a->second > b->second);
}

int main(int argc, char const *argv[])
{
	int N,M,K;
	cin>>N>>M>>K;
	fill(&adjacencyMatrix[0][0],&adjacencyMatrix[0][0]+sizeof(adjacencyMatrix)/sizeof(adjacencyMatrix[0][0]),0);
	//cout<<"Filled out adj matrix"<<endl;	
	for (int i = 1; i <= N; ++i)
	{
		//cout<<"For i:"<<i<<endl;
		vertexMap[i] = new incTax(i,0);
		totalTaxCache.push_back(vertexMap[i]);
		//cout<<"test:"<<vertexMap[i]->first<<endl;
	}
	for (int i = 0; i < M; ++i)
	{
		int x,y,c;
		cin>>x>>y>>c;
		adjacencyMatrix[x][y]=c;
		adjacencyMatrix[y][x]=c;
		vertexMap[x]->second += c;
		vertexMap[y]->second += c;
	}
	for (int i = 0; i < K; ++i)
	{
	//	printVertexMap();
		sort(totalTaxCache.begin(),totalTaxCache.end(),comparePair);
	//	printtotalTaxCache();
		if(totalTaxCache[0]->second > 0)
		{
	//		cout<<"top:"<<totalTaxCache[0]->first<<endl;
			cameras.push_back(totalTaxCache[0]->first);
			for (int i = 1; i <= N; ++i)
			{
				if(vertexMap.find(i)!=vertexMap.end())
				{
					vertexMap[i]->second -= adjacencyMatrix[totalTaxCache[0]->first][i];
				}				
			}
			vertexMap.erase(totalTaxCache[0]->first);
			totalTaxCache.erase(totalTaxCache.begin());
		}
		else
			break;
	}
	//cout<<"Solution:"<<endl;
	cout<<cameras.size()<<endl;
	for (int i = 0; i < cameras.size(); ++i)
	{
		cout<<cameras[i]<<" ";
	}

	return 0;
}


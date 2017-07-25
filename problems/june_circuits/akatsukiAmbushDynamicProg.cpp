/*
https://www.hackerearth.com/june-circuits/algorithm/akatsuki-vs-leaf-circuit/description/
*/

/*
Every possibility is considered, i.e, called recursively for every element, 
using bitmask to determine which of the enemies have been picked already.
Basically backtracking, but with memoisation to reduce complexity.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<limits>
using namespace std;

long long memo[1<<20][20];
typedef pair<long long,long long> position;
std::vector<long long> Ax,Ay,Bx,By;
//long long minDist = numeric_limits<long long>::max();
int n;

long long _distance(/*position a, position b*/int a, int b)
{
	return abs(Ax[a] - Bx[b]) + abs(Ay[a] - By[b]);
}

long long backtrackAndSolve(int ally, int enemyMask)
{
	if(n == ally)
	{
		return 0; 
	}
	
	long long minDist = numeric_limits<long long>::max();

	if(memo[enemyMask][ally]==-1)
	{

		for(int i=0;i<n;i++)
		{
			if(!(enemyMask & (1<<i)))
			{
				//distance(ally,i);
				minDist = min(minDist, _distance(ally,i) + 
					backtrackAndSolve(ally+1,enemyMask | 1<<i)); 		
			}
		}
		memo[enemyMask][ally] = minDist;
		return minDist;
	}
	else
		return memo[enemyMask][ally];
}

int main(int argc, char const *argv[])
{
	//cout<<sizeof(memo[0][0])<<endl;
	fill(&memo[0][0],&memo[0][0]+sizeof(memo)/sizeof(memo[0][0]),-1);
	//cout<<memo[200][19];
	cin>>n;
	Ax.resize(n);
	Ay.resize(n);
	Bx.resize(n);
	By.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>Bx[i]>>By[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>Ax[i]>>Ay[i];
	}
	cout<<backtrackAndSolve(0,0);
	return 0;
}
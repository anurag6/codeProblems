/*
Idea is to generate an array implementation of tree, populating members 
bottom to top.
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<map>

using namespace std;

long long *tournamentTree;
long long *playerList;
std::map<long long, long long> playerCount;
std::map<long long, long long> playerStrength;

long long N,Q;

long long numberOfTournamentNodes(long long players)
{
	long long sum = 0;
	if(players == 1)
		return 0;
	/*for(long long i=players;i>1;)
	{
		//cout<<"For loop "<<i;
		sum += i;
		if(i%2!=0)
		{
			i = (i+1)/2;
		}
		else
			i = i/2;
		//cout<<"End for "<<i;
	}*/
	long long _log = ceil(log2(players));
	for(long long i=1;i<=_log;i++)
	{
		sum += pow(2,i);
	}
//	cout<<"For players:"<<players<<" returning "<<sum<<endl;
	return sum;
}

void populateTournamentNode(long long position, long long player)
{
	tournamentTree[position] = player;
	std::map<long long, long long>::iterator it;
	
}

long long compare(long long a, long long b)
{
//	cout<<"compare called for "<<a<<","<<b<<endl;
	if(b==0)
		return a;
	playerCount[a]++;
	playerCount[b]++;
	if(playerStrength[a]>playerStrength[b])
		return a;
	else
		return b;
}

void populateTournamentTree()
{
	long long _numberOfTournamentNodes = numberOfTournamentNodes(N);
	if(_numberOfTournamentNodes < 2)
		return;
	//tournamentTree.resize(_numberOfTournamentNodes+1);
	tournamentTree = new long long[_numberOfTournamentNodes + 1];
	long long left = _numberOfTournamentNodes - pow(2,ceil(log2(N))) + 1;
	long long right = left + N -1;
//	cout<<"left:"<<left<<" right:"<<right<<endl;
	for(long long i=1; i<=N; i++)
	{
		tournamentTree[left+i-1] = i;
	}
	left = (left+1)/2-1;
	right = (right+1)/2-1;
//	cout<<"Starting populating parent levels. "<<endl;
	while((left > 0)&&(right > 0)&&(left < right))
	{
//		cout<<"left:"<<left<<" right:"<<right<<endl;
		for(long long i =left; i<=right; i++)
		{
			tournamentTree[i] = compare(tournamentTree[2*i+1],tournamentTree[2*i+2]);
		}
		left = (left+1)/2-1;
		right = (right+1)/2-1;
	}
	compare(tournamentTree[1],tournamentTree[2]);
}

void populateTournamentList()
{
	playerList = new long long[N+1];
	for (long long i = 1; i <= N; ++i)
	{
		playerList[i]=i;
	}	
	long long numPasses = ceil(log2(N)) - 1;
	long long left;
	long long right;
	for (long long i = 0; i <= numPasses; ++i)
	{
		long long jump = pow(2,i);
		left = 1;
		right = left+jump;
	//	cout<<"left:"<<left<<" right:"<<right<<endl;
		//char x;
		//cin>>x;
		while(left <= N && right <= N)
		{
		//	cout<<"left:"<<left<<" right:"<<right<<endl;
			playerList[left] = compare(playerList[left],playerList[right]);

			left = right + jump;
			right = left + jump;
		}		
	}
}

void print_playerCount()
{
	cout<<"print_playerCount:"<<endl;
	map<long long, long long>::iterator it;
	for(it=playerCount.begin();it!=playerCount.end();it++)
	{
		cout<<"("<<it->first<<","<<it->second<<") ";
	}
	cout<<endl;
}

void print_tournamentTree()
{
	cout<<"print_tournamentTree:"<<endl;
	vector<long long>::iterator it;
	for(long long i=1;i<(sizeof(tournamentTree)/sizeof(tournamentTree[0]));i++)
	{
		cout<<"("<<i<<","<<tournamentTree[i]<<") ";
	}
	cout<<endl;
}

void print_playerList()
{
	cout<<"print_playerList:"<<endl;
	for (long long i = 1; i <= N; ++i)
	{
		cout<<"("<<i<<","<<playerList[i]<<") ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	cin>>N>>Q;
	for(long long  i=1;i<=N;i++)
	{
		long long x;
		cin>>x;
		playerStrength[i] = x;
		playerCount[i]=0;
	}
	//populateTournamentTree();
	populateTournamentList();
	//print_playerList();

	//print_tournamentTree();
	//print_playerCount();

	for(long long i = 0; i<Q; i++)
	{
		long long x;
		cin>>x;
		cout<<playerCount[x]<<endl;
	}
	return 0;
}

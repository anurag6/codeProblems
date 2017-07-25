#include<iostream>
#include<vector>
#include<stdlib.h>
#include<deque>
#include<algorithm>

using namespace std;

struct Position{
	long long x;
	long long y;
	Position(){
		x=0;
		y=0;
	}
	Position(long long a, long long b){
		x=a;
		y=b;
	}
	long long distance(const Position &b){
		return abs(this->x - b.x) + abs(this->y - b.y);
	}
	friend ostream& operator<< (ostream& stream, const Position& ed){
		stream<<"x:"<<ed.x<<" y:"<<ed.y<<"   ";
	}
};
struct enemyAllyDistance{
	long long distance;
	int ally;
	enemyAllyDistance(){
		distance=0;
		ally = 0;
	}	
	enemyAllyDistance(long long d, int a){
		distance=d;
		ally=a;
	}
	bool operator< (const enemyAllyDistance &b){
		return this->distance < b.distance;
	}
	friend ostream& operator<< (ostream& stream, const enemyAllyDistance& ed){
		stream<< "vertex:"<<ed.ally << " Distance:" << ed.distance <<endl;
	}
};

vector<Position> enemyList;
vector<Position> allyList;
vector<int> allyAssignment;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		long long x,y;
		cin>>x>>y;
		Position *newEnemy=new Position(x,y);
		enemyList.push_back(*newEnemy);
	}
	for(int i=0;i<N;i++){
		long long x,y;
		cin>>x>>y;
		Position *newAlly=new Position(x,y);
		allyList.push_back(*newAlly);
	}
	for(int i=0;i<N;i++){
		cout<<" "<<enemyList[i];
	}
	cout<<endl;
	vector<deque<enemyAllyDistance> > enemyDistance(N,std::deque<enemyAllyDistance>(N));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			long long distance = enemyList[i].distance(allyList[j]);
			cout<<"For i:"<<i<<" and j:"<<j<<" distance:"<<distance<<endl;
			enemyAllyDistance *ed = new enemyAllyDistance(distance,j);
			enemyDistance[i].push_back(*ed);
		}
		sort(enemyDistance[i].begin(),enemyDistance[i].end());
	}
	for (int i = 0; i < N; ++i)
	{
		cout<<"For enemy "<<i<<": ";
		for (deque<enemyAllyDistance>::iterator it = enemyDistance[i].begin();
				it!=enemyDistance[i].end();it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	return 0;
}
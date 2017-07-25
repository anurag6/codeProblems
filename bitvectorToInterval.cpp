#include<iostream>
#include<vector>
#include<utility>
using namespace std;
vector<bool> bitMap;

void findInterval(vector<bool> bitMap, vector<pair<int,int> >& intervalvector)
{
	for (int i = 0; i < bitMap.size(); ++i)
	{		
		if (bitMap[i]==true)
		{
			int j;
			for(j=i;j<bitMap.size() && bitMap[j]==true;j++);
			intervalvector.push_back(make_pair(i,j-1));
			i=j-1;
		}
	}
}

void markInterval(vector<bool> &bitMap, vector<pair<int,int> > intervalvector)
{
	for (int i = 0; i < intervalvector.size(); ++i)
	{			
		for (int k = intervalvector[i].first; k <= intervalvector[i].second; ++k)
		{
			bitMap[k] = true;
		}
	}
}

void printPair(pair<int,int> p)
{
	cout<<"("<<p.first<<","<<p.second<<")"<<endl;
}
void printvector(vector<bool> boolMap){
	cout<<"Bitmap:"<<endl;
	for (int i = 0; i < boolMap.size(); ++i)
	{
		cout<<(int)boolMap[i];
	}
	cout<<endl;
}
void printvector(vector<pair<int,int> > pairvector)
{
	cout<<"Pairvector:"<<endl;
	for (std::vector<pair<int,int> >::iterator i = pairvector.begin(); i != pairvector.end(); ++i)
	{
		cout<<(*i).first;
		printPair(*i);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {0,0,1,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,1,1,0,0,1,1};
	vector<bool> bitMap (arr,arr+(sizeof(arr)/sizeof(arr[0])));
	printvector(bitMap);
	vector<pair<int,int> > intvector;
	findInterval(bitMap,intvector);
	printvector(intvector);
	std::vector<bool> v(bitMap.size(),false);
	cout<<"Reversing. Init:";
	printvector(v);
	markInterval(v,intvector);
	printvector(v);
	return 0;
}



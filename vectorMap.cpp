#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class VertexTaxInfo{
	int taxChange;
	int vertex;
public:
	VertexTaxInfo(int a, int b){vertex=a; taxChange=b;}
	const int getTaxChange(){return taxChange;}
	const int getVertex(){return vertex;}

	void setTaxChange(int x){taxChange = x;}
	void setVertex(int x){vertex = x;}
	bool operator<(const VertexTaxInfo &b){
		return this->taxChange < b.taxChange;
	}
	static bool greaterThan(const VertexTaxInfo &a,const VertexTaxInfo &b){
		return a.taxChange > b.taxChange;
	}
};

std::vector<VertexTaxInfo> container;
std::vector<VertexTaxInfo*> _map;

int main(){
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		//cout<<"\nfor i"<<i;
		VertexTaxInfo* vt = new VertexTaxInfo(i+1,0);
		//vt.setVertex(i+1);
		//vt.setTaxChange(100-10*i);
		//cout<<"\nPushing object";
		container.push_back(*vt);
		//cout<<"\nAssigning to map";
		//VertexTaxInfo* pt = vt;
		_map.push_back(vt);
	}
	int **taxChangeCache;
	taxChangeCache = new int*[501];
	float totalTaxChange=0;
	for(int i=0;i<=500;i++)
		taxChangeCache[i]=new int[501];
	for(int i=0;i<M;i++){
		int u,v,c;
		cin>>u>>v>>c;
		totalTaxChange += c;
		taxChangeCache[u][v]=c;
		taxChangeCache[v][u]=c;
		container[u-1].setTaxChange(container[u-1].getTaxChange() + c);
		container[v-1].setTaxChange(container[v-1].getTaxChange() + c);		
	}
	/*for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<taxChangeCache[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//cout<<"\nDone assignment. Calling sort";
	float avgTaxChange = totalTaxChange/(float)N;
	//cout<<"\nAverage tax change:"<<avgTaxChange;
	float avgVertices = 2.0*M/N;
	//cout<<"\nAverage vertices:"<<avgVertices;
	float score=0;
	int totalProfit =0;
	//int camerasNo = 0;
	vector<int> cameras;
	for (int i = 0; i < K; ++i)
	{
		sort(container.begin()+i,container.end(),VertexTaxInfo::greaterThan);
		/*for(int x=0;x<_map.size();x++){
			cout<<" "<<container[x].getVertex()<<","<<container[x].getTaxChange();
		}*/
		cout<<endl;
		totalProfit+=container[i].getTaxChange();
		float tempScore=totalProfit/(avgVertices*avgTaxChange*(i+1));
		if(tempScore>score){
			score = tempScore;
			cameras.push_back(container[i].getVertex());
			for(int j=1;j<=N;j++){
				if(taxChangeCache[i+1][j]!=0)
				{
					container[j-1].setTaxChange(container[j-1].getTaxChange() - taxChangeCache[i+1][j]);
					taxChangeCache[i+1][j]=0;
					taxChangeCache[j][i+1]=0;					
				}
			}
		}
		else
			break;
	}
	//sort(container.begin(),container.end());
	//cout<<"\ncalled sort";
	cout<<cameras.size()<<endl;
	for(int i=0;i<cameras.size();i++){
		cout<<cameras[i]<<" ";//<<","<<container[i].getTaxChange();
	}
	//cout<<endl;
	for(int i=0;i<_map.size();i++){
		//cout<<" "<<_map[i]->getVertex()<<","<<_map[i]->getTaxChange();
	}

	return 0;
}

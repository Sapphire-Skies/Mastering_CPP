#include<bits/stdc++.h>
#include<cmath>

using namespace std;
/*class Edge{
	public:
	long int src,dest;
	long long int weight;
	Edge(long int s,long int d,long long int w){
		src=s;
		dest=d;
		weight=w;
	}
};*/

long long int diff(vector<long int> x,vector<long int> y){
	long long int diff=0;
	for(long int i=0;i<x.size();i++){
		diff+=abs(x[i]-y[i]);
	}
	return diff;
}

long int maxKey(long int key[] ,bool mstSet[] , long int v){
	long max=-1;
	long index=-1;
	for(long int i=0;i<v;i++){
		if(mstSet[i]==false && key[i]>max){
			max=key[i];
			index=i;
		}
	}return index;
}

void MST(vector <vector<long long int> > graph,long int v){
	//long int v=graph.size();
	long int parent[v];
	long int key[v];
	bool mstSet[v];
	for(long int i=0;i<v;i++){
		key[i]=-1;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(long count=0;count<v-1;count++){
		long u=maxKey(key,mstSet,v);
		mstSet[u]=true;
		for(long j=0;j<v;j++){
			if(graph[u][j]!=0 && mstSet[j]==false && graph[u][j]>key[j]){
				parent[j]=u;
				key[j]=graph[u][j];
			}
		}
	}
	long long int sum=0;
	for(long int i=1;i<v;i++){
		sum+=graph[parent[i]][i];
	}
	cout<<sum<<"\n";
}



int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    short int d;
	long int n,i,j;
	cin>>n>>d;
	//Edge e=new Edge[n];
	vector <vector<long int> > A(n,vector<long int>(d));
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			cin>>A[i][j];
		}
	}
	vector <vector<long long int> > graph(n, vector <long long int>(n,0));
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			long long int weight =diff(A[i],A[j]);
			graph[i][j]=weight;
			graph[j][i]=weight;
		}
	}
	MST(graph,n);
	return 0;
}

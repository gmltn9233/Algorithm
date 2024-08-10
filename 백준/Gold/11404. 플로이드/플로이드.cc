#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
int n,m,a,b,c;
int dist[104][104];
int main(){
	cin>>n;
	cin>>m;
	fill(&dist[0][0],&dist[0][0]+104*104,INF);
	for(int i=0; i<m; i++){
		cin>>a>>b>>c;
		if(dist[a][b]>c) dist[a][b]=c;
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j || dist[i][j]==INF) cout<<0<<" ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 987654321;
int n,m,s,d,u,v,p,ret=INF;
int edge[503][503];
int dist[503];
priority_queue<int,vector<int>,greater<int>> pq;

void dijkstra(){
	fill(dist,dist+504,INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,s});
	dist[s]=0;
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		for(int i=0; i<n; i++){
			if(edge[here][i] == -1) continue;
			int _dist = edge[here][i];
			if(dist[i] > dist[here] + _dist){
				dist[i] = dist[here] + _dist;
				pq.push({dist[i],i});
			}
		}
	}
}
void erase_edge(){
	queue<int> q;
	q.push(d);
	while(q.size()){
		int dis = q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(dist[dis] == dist[i] + edge[i][dis] && edge[i][dis] != -1){
				edge[i][dis] = -1;
				q.push(i);
			}
			
		}
	}
}
int main() {
	while(true){
		cin>>n>>m;
		if(n==0 && m==0) break;
		cin>>s>>d;
		memset(edge,-1, sizeof(edge));
		while(m--){
			cin>>u>>v>>p;
			edge[u][v]=p;
		}
		dijkstra();
		erase_edge();
		dijkstra();
		ret = dist[d];
		if(ret==INF) cout<<"-1\n";
		else cout<<ret<<"\n"; 
	}
	return 0;
}


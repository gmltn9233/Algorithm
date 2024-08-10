#include<bits/stdc++.h> 
using namespace std;
const long long INF = 987654321;
long long n,m,a,b,c;
long long dist[505];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	fill(dist,dist+n+1,INF);
	vector<pair<int,int>> adj[504];
	for(int i=0; i<m; i++){
		cin>>a>>b>>c;
		adj[a-1].push_back({b-1,c});
	}
	dist[0]=0;
	queue<int> q;
	for(int i=0; i<n; i++){
		for(int here = 0; here<n; here++){
			for(auto there : adj[here]){
				int d = there.second;
				int to = there.first;
				if(dist[here] != INF && dist[here] + d < dist[to]){
					if(i== n-1) q.push(to);
					dist[to] = dist[here] +d;
				}
			}
		}
	}
	if(q.size()) cout<<-1<<"\n";
	else{
		for(int i=1; i<n; i++){
			cout<<(dist[i]==INF ? -1 : dist[i])<<"\n";
		}
	}
 	return 0;
}

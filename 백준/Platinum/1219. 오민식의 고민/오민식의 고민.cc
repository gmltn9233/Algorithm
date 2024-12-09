#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m,S,E,s,e,p;
vector<pair<int,int>> route[51];
long long dist[51],price[51],visited[51];
bool flag;
int main() {
	cin>>n>>S>>E>>m; 
	for(int i=0; i<m; i++){
		cin>>s>>e>>p;
		route[s].push_back({e,p});
	}
	for(int i=0; i<n; i++){
		cin>>price[i];
	}
	
	queue<int> q;
	fill(dist,dist+51, -INF);
	dist[S] = price[S];
	for(int i=0; i<n; i++){
		for(int here=0; here<n; here++){
			for(auto there : route[here]){
				int now = there.first;
				int now_dist = there.second;
				if(dist[here] != -INF && dist[now] < dist[here] + price[now] - now_dist){
					dist[now] = dist[here] + price[now] - now_dist;
					if(i==n-1){
						q.push(here);
					}
				}
			}
		}
	}
	
	while(q.size()){
		int here = q.front();
		q.pop();
		for(auto there : route[here]){
			if(there.first == E){
				flag = true;
				break;
			}
			if(!visited[there.first]){
				visited[there.first] = 1;
				q.push(there.first);
			}
		}
		if(flag) break;
	}
	
	if(dist[E] == -INF) cout<<"gg";
	else if(flag) cout<<"Gee";
	else cout<<dist[E];
	
	return 0;
}

// n개의 도시 (0~n-1)
// m개의 교통 수단
 
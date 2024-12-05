#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,S,s,E,e,m,p; 
bool flag;
vector<pair<int,int>> route[51];
long long price[51], dist[51];
int visited[104];
void bellmanFord(){
	fill(dist,dist+51, -INF);
	dist[S] = price[S];
	queue<int> q;
	for(int i=0; i<n; i++){
		for(int here=0; here<n; here++){
			for(auto there: route[here]){
				int next = there.first;
				int next_dist = there.second;
				if(dist[here] != -INF && dist[next] < dist[here] + price[next] - next_dist){
					dist[next] = dist[here] + price[next] - next_dist;
					if(i==n-1) q.push(here);
				}
			}
		}
	}
	
	while(q.size()){
		int here = q.front();
		q.pop();
		for(auto there : route[here]){
			if(there.first == E){
				flag = true; break;
			}
			if(!visited[there.first]){
				visited[there.first] = 1;
				q.push(there.first);
			}
		}
		if(flag) break;
	}
	if(dist[E] == -INF) cout<<"gg";
	else if (flag) cout<<"Gee";
	else cout<<dist[E];
}
int main() {
	cin>>n>>S>>E>>m;
	for(int i=0; i<m; i++){
		cin>>s>>e>>p;
		route[s].push_back({e,p});
	}
	for(int i=0; i<n; i++){
		cin>>price[i];
	}
	bellmanFord();
	return 0;
}

// 최대한 많이 팔아서 최대 이윤
// n개의 도시 (0번~n-1번)
// a 시작 b 끝
// m 개의 교통수단 

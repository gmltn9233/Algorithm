#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m,a,b,d,ret;
vector<pair<int,int>> route[4001];
int dist[4001],dist_wolf[4001][2];
void dikstra(){
	fill(dist,dist+4001,INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dist[1] = 0;
	pq.push({0,1});
	while(pq.size()){
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if(dist[here] != here_dist) continue;
		for(pair<int,int> there : route[here]){
			int next = there.second;
			int next_dist = there.first;
			if(dist[next] > dist[here] + next_dist){
				dist[next] = dist[here] + next_dist;
				pq.push({dist[next],next});
			}
		}
	}
}
void dikstra2(){
	fill(&dist_wolf[0][0], &dist_wolf[0][0]+4001*2 , INF);
	priority_queue<tuple<int,int,bool>,vector<tuple<int,int,bool>>, greater<tuple<int,int,bool>>> pq;
	dist_wolf[1][0] = 0;
	pq.push(make_tuple(0,1,0));
	while(pq.size()){
		int d,here,cnt;
		tie(d,here,cnt) = pq.top();
		pq.pop();
		if(dist_wolf[here][cnt] != d) continue;
		for(pair<int,int> there : route[here]){
			int next = there.second;
			int next_dist = !cnt ? there.first/2 : there.first*2;
			if(dist_wolf[next][!cnt] > dist_wolf[here][cnt] + next_dist){
				dist_wolf[next][!cnt] = dist_wolf[here][cnt] + next_dist;
				pq.push(make_tuple(dist_wolf[next][!cnt], next, !cnt));
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>a>>b>>d;
		route[a].push_back({d*2,b});
		route[b].push_back({d*2,a});
	}
	dikstra();  
    dikstra2();  
    for(int i=2; i<=n; i++){
    	int d = min(dist_wolf[i][0], dist_wolf[i][1]);
    	if(d>dist[i]) ret ++;
	}
	cout<<ret;
	return 0;
}


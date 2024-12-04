#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,m,a,b,d,ret;
vector<pair<int,int>> route[4001];
int dist[4001], dist2[4001][2];
void dikstra(){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push({0,1});
	fill(dist,dist+4001,INF);
	dist[1]=0;
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
	priority_queue<tuple<int,int,bool>, vector<tuple<int,int,bool>>, greater<tuple<int,int,bool>>> pq;
	pq.push(make_tuple(0,1,0));
	fill(&dist2[0][0], &dist2[0][0] + 4001 * 2 , INF);
	dist2[1][0]=0;
	while(pq.size()){
		int here,here_dist,flag;
		tie(here_dist,here,flag) = pq.top();
		pq.pop();
		if(dist2[here][flag] != here_dist) continue;
		for(pair<int,int> there : route[here]){
			int next = there.second;
			int next_dist = flag ? there.first*2 : there.first/2;
			if(dist2[next][!flag] > dist2[here][flag] + next_dist){
				dist2[next][!flag] = dist2[here][flag] + next_dist;
				pq.push(make_tuple(dist2[next][!flag],next,!flag));
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
		int fox = dist[i];
		int wolf = min(dist2[i][0],dist2[i][1]);
		if(fox<wolf) ++ret;
	}
	cout<<ret;
	return 0;
}


// 14:00 start
// n개의 그루터기, m개의 오솔길 
// 여우와 늑대 모두 1번에 살고 있음 
// 여우 일정한 속도 
// 늑대 2배속도 1/2배 속도 반복 
// 여우가 늑대보다 먼저 도착하는 그루터기의 수 ? 
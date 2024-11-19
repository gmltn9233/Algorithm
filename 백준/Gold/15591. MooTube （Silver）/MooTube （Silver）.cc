#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,q,a,b,c,k,v;
vector<pair<int,int>> graph[5001];
int visited[5001];
int bfs(int k, int v){
	visited[v] = 1;
	int cnt = 0;
	queue<int> q;
	q.push(v);
	while(q.size()){
		int now = q.front();
		q.pop();
		for(int i=0; i<graph[now].size(); i++){
			pair<int,int> next = graph[now][i];
			if(visited[next.first]) continue;
			if(next.second >= k){
				q.push(next.first);
				++cnt;
				visited[next.first] = 1;
			}
		}
	}
	return cnt;
}
int main()
{
	cin>>n>>q;
	for(int i=0; i<n-1; i++){
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
		graph[b].push_back({a, c});
	}
	for(int i=0; i<q; i++){
		cin>>k>>v;
		fill(visited,visited+5001, 0);
		int ret = bfs(k,v);
		cout<<ret<<"\n";
	}
	

	return 0;
}

// 연관동영상
// USADO : 두 쌍의 연관성 단위
// USADO K이상인 모든 동영상 추천 
// K에 대한 추천 동영상의 개수 
#include<bits/stdc++.h>
using namespace std; 
int n,m;
int room_cnt;
int max_room;
int dy[4]={0,-1,0,1};
int dx[4]={-1,0,1,0};
int a[55][55];
int visited[55][55];
int compSize[2501];
int big;
int dfs(int y,int x,int cnt){
	if(visited[y][x]) return 0;
	visited[y][x] = cnt;
	int ret = 1;
	for(int i=0; i<4; i++){
		if(!(a[y][x] & (1 << i))){
			int ny= y+dy[i];
			int nx= x+dx[i];
			ret += dfs(ny,nx,cnt);
		}
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				++room_cnt;
				compSize[room_cnt]=dfs(i,j,room_cnt);
				max_room=max(max_room,compSize[room_cnt]);
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(i+1<m){
				int a = visited[i+1][j];
				int b = visited[i][j];
				if(a!=b){
					big = max(big,compSize[a]+compSize[b]);
				}
			}
			if(j+1<n){
				int a = visited[i][j+1];
				int b = visited[i][j];
				if(a!=b){
					big = max(big,compSize[a]+compSize[b]);
				}
			}
		}
	}
	cout<<room_cnt<<'\n'<<max_room<<'\n'<<big<<'\n';
	return 0;
}

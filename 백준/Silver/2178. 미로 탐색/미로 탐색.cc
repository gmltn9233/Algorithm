#include<bits/stdc++.h> 
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int n,m;
int y,x;
int a[104][104],visited[104][104];
int main(){
	cin>>n>>m;
	for(int i=0;i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d",&a[i][j]);
		}
	}
	queue<pair<int,int>> q;
	visited[0][0]=1;
	q.push({0,0});
	while(q.size()){
		tie(y,x)=q.front();
		q.pop();
		for(int i=0;i<4; i++){
			int ny=y+dy[i];
			int nx=x+dx[i];
			if(ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0) continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx]=visited[y][x]+1;
			q.push({ny,nx});
		}
	}
	cout<<visited[n-1][m-1];
	return 0;
}
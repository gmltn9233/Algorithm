#include <bits/stdc++.h>
using namespace std;
int ret;
int dy[9]={-1,-1,0,1,1,1,0,-1,0};
int dx[9]={0,1,1,1,0,-1,-1,-1,0};
char a[10][10];
int visited[10][10][10];
int main() {
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin>>a[i][j];
		}
	}
	queue<tuple<int,int,int>> q;
	q.push(make_tuple(0,7,0));
	visited[0][7][0] = 1;
	while(q.size()){
		int t,y,x;
		tie(t,y,x) = q.front();
		q.pop();
		if(y==0 && x==7) ret = 1;
		for(int i=0; i<9; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			int nt = min(t+1,8);
			if(ny < 0 || ny >= 8 || nx < 0 || nx >=8) continue;
			if(ny-t >= 0 && a[ny-t][nx] == '#') continue;
			if(ny-t -1 >= 0 && a[ny-t-1][nx] == '#') continue;
			if(visited[nt][ny][nx]) continue;
			visited[nt][ny][nx] = 1;
			q.push(make_tuple(nt,ny,nx));
		}
	}
	
	cout<<ret;
	
	
	return 0;
}




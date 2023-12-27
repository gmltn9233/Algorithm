#include<bits/stdc++.h>
using namespace std;
const int max_n = 21;
const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
int R,C,visited[30],ret;
string s;
char a[max_n][max_n];

void bfs(int y, int x, int cnt){
	ret=max(ret,cnt);
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||ny>=R||nx<0||nx>=C) continue;
		if(visited[(int)a[ny][nx]-'A']==0){
			visited[(int)a[ny][nx]-'A']=1;
			bfs(ny,nx,cnt+1);
			visited[(int)a[ny][nx]-'A']=0;
		}
	}
	return;
}

int main(){
	cin>>R>>C;
	for(int i=0; i<R;i++){
		for(int j=0; j<C; j++){
			cin>>a[i][j];
		}
	}
	visited[(int)a[0][0]-'A']=1;
	bfs(0,0,1);
	cout<< ret;
    return 0;
}
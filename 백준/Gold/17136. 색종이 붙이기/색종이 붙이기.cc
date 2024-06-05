#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
int a[11][11];
int paper[5] ={5,5,5,5,5};
int ret = INF;
bool check(int y, int x, int cnt){
	for(int i=y; i<y+cnt; i++){
		for(int j=x; j<x+cnt; j++){
			if(i>=10 || j>=10) return false;
			if(a[i][j]==0) return false;
		}
	}
	return true;
}
//draw
void draw(int y, int x, int cnt,int num){
	for(int i=y; i<y+cnt; i++){
		for(int j=x; j<x+cnt; j++){
			a[i][j]=num;
		}
	}
}
//dfs
void dfs(int y, int x, int cnt){
	if(cnt>=ret) return;
	//cout<<"y: "<<y<<" x:"<<x<<"\n";
	if(x==10){
		dfs(y+1,0,cnt);
		return;
	}
	if(y==10) {
		ret = min(cnt,ret);
		return;
	}
	if(a[y][x]==0){
		dfs(y,x+1,cnt);
		return;
	}
	for(int i=5; i>=1; i--){
		if(paper[i-1]==0) continue;
		if(check(y,x,i)){
			draw(y,x,i,0);
			--paper[i-1];
			dfs(y,x+i,cnt+1);
			draw(y,x,i,1);
			++paper[i-1];
		}
	}
	return;
}
int main() {
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cin>>a[i][j];
		}
	}
	dfs(0,0,0);
	cout<< (ret == INF ? -1 : ret); 
	return 0;
}
// 탐색 방향을 어떻게 할 것인가?
// 색칠한 맵 원상복귀 로직?


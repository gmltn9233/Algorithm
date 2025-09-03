#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[51][51],visited[51][51];
int ry,rx,d,ret;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,1,0,-1};
bool flag=true;
bool bin(int y,int x){
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]) continue;
		if(a[ny][nx]==0){
			return true;
		}
	}
	return false;
}

void go(int y,int x,int d){

	visited[y][x]=1;
	if(bin(y,x)){
		for(int i=0; i<4; i++){
			d =(d+3)%4;
			int ny=y+dy[d];
			int nx=x+dx[d];
			if(ny<0||ny>=n||nx<0||nx>=m||visited[ny][nx]||a[ny][nx]==1){
				continue;
			}
			if(flag){
				go(ny,nx,d);
			}
			
		}
	}
	else{
		int dd=(d+2)%4;
		int ny=y+dy[dd];
		int nx=x+dx[dd];
		if(a[ny][nx]==1){
			flag=false;
		}
		if(a[ny][nx]!=1&&flag){
			go(ny,nx,d);
		}
	}
}

int main(){
	cin>>n>>m;
	cin>>ry>>rx>>d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	go(ry,rx,d);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]==0&&visited[i][j]) ++ret;
		}
	}
	cout<<ret;
	return 0;
} 
// 청소기는 바라보는 방향이 있음 
// 1.아직 청소하지않았다면 현재칸 청소
// 2. 현재 칸의 주변 4칸 모두 청소되었다면
// 		후진이 가능하면 후진하고 1번
//		후진할 수 없으면 작동을 멈춤
///3. 현재 칸의 주변 4칸 중 청소되지않은 칸이 있다면
//    1. 반시계방향 90 회전
//	  2. 바라보는 방향 앞쪽칸이 청소되지않은 경우 한칸 전진
//    3.  1번으로 돌아감 
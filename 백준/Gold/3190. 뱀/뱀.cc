#include<bits/stdc++.h>
using namespace std;
int n,k,l,ret;
queue<pair<int,char>> q;
queue<pair<int,int>> tail;
int a[101][101];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
void go(int y,int x,int idx,int time){
	int ny = y+dy[idx];
	int nx = x+dx[idx];
	if(ny<0 || ny>=n || nx<0 || nx>=n || a[ny][nx]==2){
		ret = time;
		return;
	}
	tail.push({ny,nx});
	if(a[ny][nx]==1){
		a[ny][nx]=2;
	}
	if(a[ny][nx]==0){
		a[ny][nx]=2;
		a[tail.front().first][tail.front().second]=0;
		tail.pop();
	}
	if(q.front().first == time){
		if(q.front().second == 'L'){
			--idx;
			if(idx==-1){
				idx=3;
			}
		}
		else{
			++idx;
			if(idx==4){
				idx=0;
			}
		}
		q.pop();
	}
	go(ny,nx,idx,time+1);
}
int main(){
	cin>>n;
	cin>>k;
	for(int i=0; i<k; i++){
		int x,y;
		cin>>y>>x;
		a[y-1][x-1]=1;
	}
	cin>>l;
	for(int i=0; i<l; i++){
		int t;
		char c;
		cin>>t>>c;
		q.push({t,c});
	}
	tail.push({0,0});
	a[0][0]=2;
	go(0,0,0,1);
	cout<<ret;
	return 0;
}
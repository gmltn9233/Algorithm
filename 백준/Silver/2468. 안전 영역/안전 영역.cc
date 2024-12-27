#include<bits/stdc++.h> 
using namespace std;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[104][104],visited[104][104],b[104][104];
int n,ret;
int sol=1;
void dfs(int y,int x,int d){
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n) continue;
		if(visited[ny][nx]==0&&a[ny][nx]>d){
			dfs(ny,nx,d);
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<104;i++){
		fill(&visited[0][0],&visited[0][0]+104*104,0);
		ret=0;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(visited[j][k]==0&&a[j][k]>i){
					dfs(j,k,i);
					ret++;
				}
			}
		}
		sol=max(sol,ret);
	}
	cout<<sol;
	return 0;
}
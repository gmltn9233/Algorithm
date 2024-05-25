#include<bits/stdc++.h> 
using namespace std;
int m,n,k;
int sy,sx,ey,ex;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int a[101][101],visited[101][101];
int ret=0;
int cnt=1;
vector<int> va;
void dfs(int y, int x){
	visited[y][x]=1;
	for(int i=0;i<4;++i){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||nx<0||ny>=m||nx>=n) continue;
		if(visited[ny][nx]||a[ny][nx]==0) continue;
		++cnt;
		dfs(ny,nx);
	}
}
int main(){
	cin>>m>>n>>k;
	fill(&a[0][0],&a[0][0]+101*101,1);
	for(int i=0;i<k;i++){
		cin>>sx>>sy>>ex>>ey;
		for(int j=sy;j<ey;++j){
			for(int k=sx; k<ex; ++k){
				a[j][k]=0;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0; j<n; j++){
			if(visited[i][j]==0&&a[i][j]==1){
				dfs(i,j);
				va.push_back(cnt);
				cnt=1;
			}
		}
	}
	cout<<va.size()<<'\n';
	sort(va.begin(),va.end());
	for(int i: va){
		cout<< i << " ";
	}
	
	
	
	return 0;
}
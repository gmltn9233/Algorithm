#include<bits/stdc++.h> 
using namespace std;
int n,m,d[51][51];
char a[51][51];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int ret;
int visited[51][51];
int go(int y, int x){
	if(y<0 || y>=n || x<0 || x>=m ||a[y][x]=='H'){
		return 0;
	}
	if(visited[y][x]){
		cout<<-1;
		// 재방문시 바로 종료
		exit(0);
	}
	//메모이제이션
	int &ret =d[y][x];
	if(ret) return ret;
	
	visited[y][x]=1; //방문 표시
	int num = a[y][x]-'0';
	for(int i=0; i<4; i++){
		int ny = y+dy[i]*num;
		int nx = x+dx[i]*num;
		ret = max(ret,go(ny,nx)+1);
	}
	visited[y][x]=0; //방문 해제
	return ret;
}
int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		for(int j=0; j<m; j++){
			a[i][j]=s[j];
		}
	}
	cout<<go(0,0);
	return 0;
}

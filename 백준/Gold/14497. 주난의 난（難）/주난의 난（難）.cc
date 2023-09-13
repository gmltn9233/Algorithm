#include <stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
char arr[304][304];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int visited[304][304];
int n,m,y1,x1,y2,x2;
int cnt=0;
void go(int y, int x){
	visited[y][x]=1;
	for(int i=0; i<4; i++){
		int ny=y+dy[i];
		int nx=x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=m) continue;
		if(visited[ny][nx]) continue;
		if(arr[ny][nx]=='0'){
			go(ny,nx);
		}
		if(arr[ny][nx]=='1'||arr[ny][nx]=='#'){
			arr[ny][nx]='0';
			visited[ny][nx]=1;
		}
	}
}
int main () {
	scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
	y1--;
	x1--;
	y2--;
	x2--;
	for(int i=0; i<n; ++i){
		scanf("%s", arr[i]); 
	}
	while(arr[y2][x2]=='#'){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				visited[i][j]=0;
			}
		}
		go(y1,x1);
		++cnt;
		
		
	}
	
	printf("%d\n",cnt);
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n;
int price[20][20],visited[20][20];
int ret=987654321,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1};


bool check(int y, int x){
	if(visited[y][x]) return false;
	for (int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0||ny>=n||nx<0||nx>=n||visited[ny][nx]) return false;
	}
	return true;
}

void eraseflower(int y, int x){
	visited[y][x]=0;
	for (int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		visited[ny][nx]=0;
	}
}

int sumFlower(int y, int x){
	visited[y][x]=1;
	int total = price[y][x];
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		visited[ny][nx]=1;
		total+=price[ny][nx];
	}
	return total;
}

void go(int cnt, int total){
	if(cnt==3){
		ret=min(ret,total);
		return;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(check(i,j)){
				go(cnt+1,total+sumFlower(i,j));
				eraseflower(i,j);
			}
 		}
	}
}

int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>price[i][j];
		}
	}
	go(0,0);
	cout<<ret;
	return 0;
}
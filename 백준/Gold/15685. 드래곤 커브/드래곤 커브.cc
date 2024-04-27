#include<bits/stdc++.h>
using namespace std;
int dragonMap[101][101];
int dy[4]={0,-1,0,1};
int dx[4]={1,0,-1,0};
int n,ret;
vector<pair<int,int>> v;
vector<int> dr;
// k세대 드래곤 만들기 
void generation(){
	int N = dr.size();
	for(int i=N-1; i>=0; i--){
		dr.push_back((dr[i]+1)%4);
	}
}
// 맵에 그림 그리기 
void draw(int y, int x, int d, int g){
	v.clear();
	dr.clear();
	//0세대 
	v.push_back({y,x});
	dr.push_back(d);
	
	for(int i=1; i<=g; i++){
		generation();
	}
	for(int i=0; i<dr.size(); i++){
		int ny = v[v.size()-1].first + dy[dr[i]];
		int nx = v[v.size()-1].second + dx[dr[i]];
		v.push_back({ny,nx});
	}
	for(int i=0; i<v.size(); i++){
		dragonMap[v[i].first][v[i].second]=1;
	}
}
// 네 꼭짓점이 모두 드래곤 커브  
void checkMap(){
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(dragonMap[i][j]==1){
				if(dragonMap[i+1][j]==1 && dragonMap[i][j+1]==1 && dragonMap[i+1][j+1]==1){
					++ret;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		int x,y,d,g;
		cin>>x>>y>>d>>g;
		draw(y,x,d,g);
	}
	checkMap();
	cout<<ret<<'\n';
	return 0;
}
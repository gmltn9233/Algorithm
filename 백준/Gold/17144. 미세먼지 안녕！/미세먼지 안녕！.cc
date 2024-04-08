#include<bits/stdc++.h>
using namespace std;
int r,c,t,ret;
int a[51][51];
int b[51][51];
vector<int> v;
vector<pair<int,int>> p;
void dustspread(int y, int x){
	int cnt=0;
	if(y+1<r&&a[y+1][x]!=-1){
		a[y+1][x]+=b[y][x]/5;
		++cnt;
	}
	if(y-1>=0 && a[y-1][x]!=-1){
		a[y-1][x]+=b[y][x]/5;
		++cnt;
	}
	if(x+1<c&&a[y][x+1]!=-1){
		a[y][x+1]+=b[y][x]/5;
		++cnt;
	}
	if(x-1>=0&&a[y][x-1]!=-1){
		a[y][x-1]+=b[y][x]/5;
		++cnt;
	}
	a[y][x]-= (b[y][x]/5)*cnt;
}
void dust(){
	p.clear();
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(a[i][j]>0){
				p.push_back({i,j});	
			}
		}
	}
	for(int i=0; i<p.size(); i++){
		b[p[i].first][p[i].second]=a[p[i].first][p[i].second];
	}
	for(int i=0; i<p.size(); i++){
		dustspread(p[i].first,p[i].second);
	}
}
void moveup(){
	for(int i=v[0]-1; i>=0; i--){
		if(i+1!=v[0]){
			a[i+1][0]=a[i][0];
		}
		a[i][0]=0;
	}
	for(int i=1; i<c; i++){
		a[0][i-1]=a[0][i];
		a[0][i]=0;
	}
	for(int i=1; i<=v[0]; i++){
		a[i-1][c-1]=a[i][c-1];
		a[i][c-1]=0;
	}
	for(int i=c-2; i>0; i--){
		a[v[0]][i+1]=a[v[0]][i];
		a[v[0]][i]=0;
	}
}
void movedown(){
	for(int i=v[1]+1; i<r; i++){
		if(i-1 != v[1]){
			a[i-1][0]=a[i][0];
		}
		a[i][0]=0;
	}
	for(int i=1; i<c; i++){
		a[r-1][i-1]=a[r-1][i];
		a[r-1][i]=0;
	}
	for(int i=r-2; i>=v[1]; i--){
		a[i+1][c-1]=a[i][c-1];
		a[i][c-1]=0;
	}
	for(int i=c-2; i>0; i--){
		a[v[1]][i+1]=a[v[1]][i];
		a[v[1]][i]=0;
	}
}
int main(){
	cin>>r>>c>>t;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>a[i][j];
			if(a[i][j]==-1){
				v.push_back(i);
			}
		}
	}
	for(int i=0; i<t; i++){
		dust();
		moveup();
		movedown();
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(a[i][j]!=-1){
				ret+=a[i][j];
			}
		}
	}
	cout<<ret;
	return 0;
}
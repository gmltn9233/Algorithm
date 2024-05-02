#include<bits/stdc++.h>
using namespace std;
int n,m; 
int a[9][9],b[9][9];
int ret = 98765421;
vector<pair<int,int>> v;
int dir[9];
void clearMap(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			b[i][j]=a[i][j];
		}
	}
}
void goUp(int y,int x){
	while(y>=0){
		if(b[y][x]==6){
			break;
		}
		b[y][x]=-1;
		--y;
	}
}
void goDown(int y,int x){
	while(y<n){
		if(b[y][x]==6){
			break;
		}
		b[y][x]=-1;
		++y;
	}
}
void goLeft(int y, int x){
	while(x>=0){
		if(b[y][x]==6){
			break;
		}
		b[y][x]=-1;
		--x;
	}
}
void goRight(int y, int x){
	while(x<m){
		if(b[y][x]==6){
			break;
		}
		b[y][x]=-1;
		++x;
	}
}
void number1(int y, int x, int d){
	if(d==0){
		goUp(y,x);
	}
	if(d==1){
		goRight(y,x);
	}
	if(d==2){
		goDown(y,x);
	}
	if(d==3){
		goLeft(y,x);
	}
}
void number2(int y, int x, int d){
	if(d%2){
		goUp(y,x);
		goDown(y,x);
	}
	else{
		goLeft(y,x);
		goRight(y,x);
	}
}
void number3(int y,int x, int d){
	if(d==0){
		goUp(y,x);
		goRight(y,x);
	}
	if(d==1){
		goRight(y,x);
		goDown(y,x);
	}
	if(d==2){
		goDown(y,x);
		goLeft(y,x);
	}
	if(d==3){
		goLeft(y,x);
		goUp(y,x);
	}
}
void number4(int y,int x, int d){
	if(d==0){
		goUp(y,x);
		goRight(y,x);
		goDown(y,x);
	}
	if(d==1){
		goRight(y,x);
		goDown(y,x);
		goLeft(y,x);
	}
	if(d==2){
		goDown(y,x);
		goLeft(y,x);
		goUp(y,x);
	}
	if(d==3){
		goLeft(y,x);
		goUp(y,x);
		goRight(y,x);
	}
}
void number5(int y, int x){
	goUp(y,x);
	goDown(y,x);
	goLeft(y,x);
	goRight(y,x);
}

int getZero(){
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(b[i][j]==0){
				++cnt;
			}
		}
	}	
	return cnt;
}
void go(){
//	for(int i=0; i<v.size(); i++){
//		cout<<dir[i]<<" ";
//	}
//	cout<<"\n";
	clearMap();
	for(int i=0; i<v.size(); i++){
		int y = v[i].first;
		int x = v[i].second;
		if(a[y][x]==1){
			number1(y,x,dir[i]);
		}
		if(a[y][x]==2){
			number2(y,x,dir[i]);
		}
		if(a[y][x]==3){
			number3(y,x,dir[i]);
		}
		if(a[y][x]==4){
			number4(y,x,dir[i]);
		}
		if(a[y][x]==5){
			number5(y,x);
		}
	}
	ret = min(ret,getZero());
}
void setDirection(int idx){
	if(idx == v.size()){
		go();
	}
	else{
		for(int i=0; i<4; i++){
			dir[idx]=i;
			setDirection(idx+1);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
			if(a[i][j]>=1 && a[i][j]<=5){
				v.push_back({i,j});
			}
		}
	}
	setDirection(0);
	cout<<ret;
	return 0;
}

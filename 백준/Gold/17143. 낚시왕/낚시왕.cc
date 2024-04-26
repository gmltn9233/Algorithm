#include<bits/stdc++.h>
using namespace std;
int r,c,m,ret;
struct shark{
	int y,x,s,d,z,death;
}a[10001];
int nowShark[101][101];
void cleanMap(){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			nowShark[i][j]=0;
		}
	}
}

void sharkMove(int idx){
	//cout<<"beforeMove\n";
	//cout<<"y: "<<a[idx].y<<" x: "<<a[idx].x<<" s: "<<a[idx].s<<" d: "<<a[idx].d<<'\n';
	int d = a[idx].d;
	if(d==1){
		int num = a[idx].s - a[idx].y;
		if(num < 0){
			a[idx].y -= a[idx].s;
		}
		else{
			int num1 = num/(r-1);
			if(num1%2){
				a[idx].y = (r-1) - (num)%(r-1);
			}
			else{
				a[idx].d = 2;
				a[idx].y = (num)%(r-1);
			}
		}
	}
	else if (d==2){
		int num = a[idx].s - ((r-1)-a[idx].y);
		if(num<0){
			a[idx].y += a[idx].s;
		}
		else{
			int num1 = num / (r-1);
			if(num1%2){
				a[idx].y = (num)%(r-1);
			}
			else{
				a[idx].d = 1;
				a[idx].y = (r-1) - (num)%(r-1);
			}
		}
	}
	else if (d==3){
		int num = a[idx].s - ((c-1)-a[idx].x);
		if(num < 0){
			a[idx].x += a[idx].s;
		}
		else{
			int num1 = num/(c-1);
			if(num1%2){
				a[idx].x = (num)%(c-1);
			}
			else{
				a[idx].d = 4;
				a[idx].x = (c-1) - (num)%(c-1);
			}	
		}
	}
	else if (d==4){
		int num = a[idx].s - a[idx].x;
		if(num < 0){
			a[idx].x -= a[idx].s;
		}
		else{
			int num1 = num/(c-1);
			if(num1%2){
				a[idx].x = (c-1) - (num)%(c-1);
			}
			else{
				a[idx].d = 3;
				a[idx].x = (num)%(c-1);
			}
		}
	}
	int index = nowShark[a[idx].y][a[idx].x];
	if(index == 0){
		nowShark[a[idx].y][a[idx].x]=idx;
	}
	else{
		if(a[index].z < a[idx].z){
			a[index].death = 1;
			nowShark[a[idx].y][a[idx].x]=idx;
			//cout<<"잡아먹음!\n";
		}
		else{
			a[idx].death = 1;
			//cout<<"잡아먹힘!\n";
		}		
	}
	//cout<<"afterMove\n";
	//cout<<"y: "<<a[idx].y<<" x: "<<a[idx].x<<" s: "<<a[idx].s<<" d: "<<a[idx].d<<" death: "<<a[idx].death<<'\n';
}

void sharksMove(){
	cleanMap();
	for(int i=1; i<=m; i++){
		if(!a[i].death){
			sharkMove(i);
		}
	}
}

void catchShark(int idx){
	for(int i=0; i<r; i++){
		if(nowShark[i][idx]){
			int sharkNum = nowShark[i][idx];
			ret += a[sharkNum].z;
			a[sharkNum].death = 1;
			//cout<<"catch"<<char('A'+sharkNum-1)<<'\n';
			return;
		}
	}
}
int main(){
	cin>>r>>c>>m;
	for(int i=1; i<=m; i++){
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].d >> a[i].z;
		a[i].y--; a[i].x--;
		nowShark[a[i].y][a[i].x]=i;
	}
	for(int i=0; i<c; i++){
		//cout<<"day"<<i+1<<"\n";
		catchShark(i);
		sharksMove();
	}
	cout<<ret;
	return 0;
}
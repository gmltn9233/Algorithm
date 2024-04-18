#include<bits/stdc++.h>
using namespace std;
int t,k;
string a[1001];
void rotateGear(int idx, int d){
	if(d==1){ // 시계방향 회전 
		int temp = a[idx][7]; 
		for(int i=7; i>0; i--){ 
			a[idx][i]=a[idx][i-1];
		}
		a[idx][0]=temp;
	}
	if(d==-1){ // 반시계 방향 회전 
		int temp = a[idx][0];
		for(int i=0; i<8; i++){
			a[idx][i]=a[idx][i+1];
		}
		a[idx][7] = temp;
	}
}
int countS(){
	int cnt = 0;
	for(int i=0; i<t; i++){
		if(a[i][0]=='1'){
			++cnt;
		}
	}
	return cnt;
} 
void go(int idx,int d){
	vector<pair<int,int>> v;
	v.push_back({idx,d});
	int now = idx;
	int nowd = d;
	while(now>0){ //왼쪽 맞닿은 톱니바퀴
		if(a[now][6]!=a[now-1][2]){
			--now;
			nowd*=-1;
			v.push_back({now,nowd});
		}
		else{
			break;
		}
	}
	now = idx;
	nowd = d;
	while(now<t-1){ //오른쪽 맞닿은 톱니바퀴
		if(a[now][2]!=a[now+1][6]){
			++now;
			nowd*=-1;
			v.push_back({now,nowd});
		}
		else{
			break;
		}
	}
	for(int i=0; i<v.size(); i++){
		rotateGear(v[i].first,v[i].second);
	}
}
int main(){
	cin >> t; // 톱니바퀴 개수 
	for(int i=0; i<t; i++){//톱니바퀴 입력
		cin>>a[i];
	}
	cin >> k; //회전 횟수 
	for(int i=0; i<k; i++){//회전 방법 입력 (톱니바퀴 번호, 방향) 
		int idx,d;
		cin>>idx>>d;
		go(idx-1,d);
	}
	// 12시 방향이 s극인 톱니바퀴의 개수 출력
	cout<< countS(); 
	return 0;
}
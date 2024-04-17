#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ret = 987654321;
int r[7][3];
int a[52][52];
int b[52][52];
int pick[7];
vector<int> v;
vector<vector<int>> vv;
void ordering(int idx){
	if(v.size()==k){
		vv.push_back(v);
		return;
	}
	for(int i=0; i<k; i++){
		if(!pick[i]){
			v.push_back(i);
			pick[i]=1;
			ordering(idx+1);
			v.erase(v.begin()+idx);
			pick[i]=0;
		}
	}
}
void copyArray(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			b[i][j]=a[i][j];
		}
	}
}
int arrayNum(){
	int minNum=987654321;
	for(int i=1; i<=n; i++){
		int num = 0;
		for(int j=1; j<=m; j++){
			num+=b[i][j];	
		}
		minNum = min(minNum,num);
	}
	return minNum;
}
void printArray(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<'\n';
	}
	cout<<'\n';
}
void rotateArray(int r,int c,int s){
	//cout<<r<<c<<s<<'\n';
	for(int d=1; d<=s; d++){
		int temp = b[r-d][c-d];
		//왼  
		for(int i=r-d+1; i<=r+d; i++){
			b[i-1][c-d]=b[i][c-d];
		}
		//아랫 변 
		for(int i=c-d+1; i<=c+d; i++){
			b[r+d][i-1]=b[r+d][i];
		}
		//오른 변 
		for(int i=r+d-1; i>=r-d; i--){
			b[i+1][c+d]=b[i][c+d];
		}
		//윗변
		for(int i=c+d-1; i>=c-d; i--){
			b[r-d][i+1]=b[r-d][i];
		}
		b[r-d][c-d+1]=temp;
	}
	//printArray();
}
void go(){
	for(int i=0; i<vv.size();i++){
		copyArray();
		for(int j=0; j<vv[i].size(); j++){
			rotateArray(r[vv[i][j]][0],r[vv[i][j]][1],r[vv[i][j]][2]);
			//printArray();
			//cout<<arrayNum()<<'\n';
		}
		ret = min(ret,arrayNum());
	}
}
int main(){
	cin>>n>>m>>k;
	ordering(0);
	for(int i=1; i<=n;i++){
		for(int j=1; j<=m; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<k; i++){
		cin>>r[i][0]>>r[i][1]>>r[i][2];
	}
	ordering(0);
	go();
	cout<<ret;
	return 0;
}
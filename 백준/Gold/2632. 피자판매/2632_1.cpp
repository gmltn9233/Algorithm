#include<bits/stdc++.h>
using namespace std;
int p,m,n,ret;
int a[1001],b[1001];
map<int ,int> aCnt, bCnt;

void pizza(int n, int arr[], int target, map<int,int> &mp){
	int num = 0;
	for(int i=0; i<n; i++){
		int total = 0,idx = i, cnt =0;
		while(total<target){
			if(idx == n) idx = 0;
			if(cnt == n) break;
			//cout<<"++total: "<<arr[idx]<<'\n';
			total += arr[idx];
			++mp[total];
			if(cnt == n-1) mp[total] = 1;
			//cout<<"++combi: "<<total<<'\n';
			++idx;
			++cnt;
		}
	}
} 

void combi(){
	for(int i=1; i<p; i++){
		ret += aCnt[i]*bCnt[p-i];
		//cout<<"a: "<<i<<" "<<aCnt[i]<<"개\n";
		//cout<<"b: "<<p-i<<" "<<bCnt[p-i]<<"개\n";
	}
}

int main(){
	cin>>p;
	cin>>m>>n;
	
	for(int i=0; i<m; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		cin>>b[i];
	}
	//cout<<"a start\n";
	pizza(m,a,p,aCnt);
	//cout<<"b start\n";
	pizza(n,b,p,bCnt);
	ret += aCnt[p];
	ret += bCnt[p];
	//cout<<"a: "<<aCnt[p]<<" b: "<<bCnt[p]<<'\n';
	combi();
	cout<<ret<<'\n';
	 
	return 0;
}

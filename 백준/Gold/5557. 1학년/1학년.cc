#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int n;
int a[101];
ll dp[101][21];
ll go(int num,int idx){
	if(num<0 || num>20) return 0;
	if(idx==n-2){
		if(num==a[n-1]) return 1;
		return 0;
	}
	
	ll &ret = dp[idx][num];
	if(ret) return ret;
	
	ret = 0;
	ret += go(num+a[idx+1],idx+1);
	ret += go(num-a[idx+1],idx+1);
	
	return ret;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<go(a[0],0);
	return 0;
}

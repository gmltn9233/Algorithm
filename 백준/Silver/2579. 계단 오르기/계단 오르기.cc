#include<bits/stdc++.h> 
using namespace std;
int n;
int a[301];
int dp[301][301];
int go(int now, int prev){
	if(now == n-1) return 0;
	if(now>=n) return -987654321;
	
	int &ret = dp[now][prev];
	if(ret) return ret;
	
	if(now-prev==1) ret = go(now+2,now)+a[now+2];
	else{
		ret = max(go(now+1,now)+a[now+1],go(now+2,now)+a[now+2]);
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<max(go(0,0)+a[0],go(1,1)+a[1]);
}

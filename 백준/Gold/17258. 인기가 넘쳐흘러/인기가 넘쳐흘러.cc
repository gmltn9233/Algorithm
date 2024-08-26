#include<bits/stdc++.h> 
using namespace std;
int n,m,k,t;
int a,b,p[301];
int dp[301][301][301];
int go(int idx, int now, int num){
	if(idx==n+1) return 0;
	
	int &ret = dp[idx][now][num];
	if(ret!=-1) return ret;
	ret = 0;
	
	if(p[idx]+now >= t){
		if(p[idx] >=t){
			ret = max(ret,go(idx+1,0,num)+1);
		}else{
			ret = max(ret,go(idx+1,now,num)+1);
		}
	}
	else{
		int cost = t-(p[idx]+now);
		if(cost <= num) ret = max(ret,go(idx+1,cost,num-cost)+1);
		ret = max(ret,go(idx+1,now,num));
	}
	
	return ret;
} 
int main(){
	cin>>n>>m>>k>>t;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		for(int i=a; i<b; i++){
			p[i]++;
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(1,0,k);
 	return 0;
} 

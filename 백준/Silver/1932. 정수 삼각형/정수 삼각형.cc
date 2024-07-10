#include<bits/stdc++.h> 
using namespace std;
int n;
int a[501][501];
long long dp[501][501];
int idx;
long long go(int now, int number){
	if(now == n) return 0;
	
	long long &ret = dp[now][number];
	if(ret) return ret;
	ret = max(ret+go(now+1,number)+a[now][number],go(now+1,number+1)+a[now][number]);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<i+1; j++){
			cin>>a[i][j];
		}
	}
	cout<<go(0,0);
}

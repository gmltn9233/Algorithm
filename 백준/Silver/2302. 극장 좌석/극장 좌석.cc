#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,a;
bool seat[41];
ll dp[41];
ll go(int idx){
	if(idx>=n-1) return 1;
	if(seat[idx]) return go(idx+1);
	
	ll &ret = dp[idx];
	if(ret) return ret;
	
	if(!seat[idx+1]) ret += (go(idx+2)+go(idx+1));
	else ret += go(idx+1);
	
	return ret;
}
int main() {
    cin>>n;
    cin>>m;
    for(int i=0; i<m; i++){
    	cin>>a;
    	seat[a-1]=true;
	}
	cout<<go(0);
	return 0;
}

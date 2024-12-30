#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
long long dp[101][101];
long long go(int y, int x){
	if(y>=n || x>=n) return 0;
	if(y == n-1 && x == n-1) return 1;
	
	long long &ret = dp[y][x];
	if(ret) return ret;
	
	int now = a[y][x];
	if(now>0){
		ret = go(y+now,x) + go(y,x+now);
	}
	
	return ret;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	
	dp[0][0]=0;
	long long temp = go(0,0);
	cout<< temp;;
	return 0;
}
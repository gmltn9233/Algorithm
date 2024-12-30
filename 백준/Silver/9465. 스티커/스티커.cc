#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[2][100001];
int dp[2][100001];
int ret;
int main() {
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<2; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		dp[0][0] = a[0][0];
		dp[1][0] = a[1][0];
		dp[0][1] = a[0][1] + dp[1][0];
		dp[1][1] = a[1][1] + dp[0][0];
		
		for(int i=2; i<n; i++){
			dp[0][i] = a[0][i] + max(dp[1][i-1],dp[1][i-2]);
			dp[1][i] = a[1][i] + max(dp[0][i-1],dp[0][i-2]);
		}
		ret = max(dp[0][n-1],dp[1][n-1]);
		cout<<ret<<"\n";
	}
	return 0;
}
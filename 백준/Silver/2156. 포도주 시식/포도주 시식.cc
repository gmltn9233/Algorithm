#include<bits/stdc++.h> 
using namespace std;
int n,a[10001];
int dp[10001];

int main(){
	cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	dp[1]=a[1];
	dp[2]=dp[1]+a[2];
	for(int i=3; i<=n; i++){
		dp[i] = max(dp[i-3]+a[i-1]+a[i],dp[i-2]+a[i]);
		dp[i] = max(dp[i-1],dp[i]);
	}
	cout<<dp[n];
}

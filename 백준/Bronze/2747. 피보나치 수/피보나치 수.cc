#include<bits/stdc++.h> 
using namespace std;
int n;
int dp[100];
int main(){
	cin>>n;
	dp[0]=0;
	dp[1]=1;
	for(int i=2; i<=n; i++){
		dp[i]=dp[i-2]+dp[i-1];
	}
	cout<<dp[n];
}

#include<bits/stdc++.h> 
using namespace std;
int n;
long long dp[1000001];
int main(){
	cin>>n;
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=15746;
	}
	cout<<dp[n]%15746;
}
//go(1,1) -> go(2,11), go(3,1)
//go(2,11)-> go(3,111), go(4,0011)
//go(3,11)-> go(4,1111), go(5,00111)
// 1 or 00 붙일 수 있음 

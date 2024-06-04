#include<bits/stdc++.h> 
using namespace std;
int n;
int L[21],J[21];
int dp[100];
int ret;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>L[i];	
	}
	for(int i=0; i<n; i++){
		cin>>J[i];
	}
	for(int i=0; i<n; i++){
		for(int j=100; j>=L[i]+1; j--){
			dp[j] = max(dp[j],dp[j-L[i]] + J[i]); 
			ret = max(ret,dp[j]);
		}
	}
	cout<<ret;
	return 0;
}


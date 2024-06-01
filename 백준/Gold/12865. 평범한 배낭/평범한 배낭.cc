#include<bits/stdc++.h> 
using namespace std;
int n,k,w,v;
int dp[100001];
int main() {
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>w>>v;
        // 유한한 경우 왼쪽 탐색
        // 무한한 경우 오른쪽 탐색
		for(int j=k; j>=w; j--){
			dp[j]= max(dp[j],dp[j-w]+v);
		}
	}
	cout<<dp[k];
	return 0;
}

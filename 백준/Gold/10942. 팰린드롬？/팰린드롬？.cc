#include<bits/stdc++.h> 
using namespace std;
int n,m,s,e;
int a[2001];
int dp[2001][2001];
int isP(int s, int e){
	int l=s,r=e;
	while(l<=r){
		if(dp[l][r]==1){
			dp[s][e]=1;
			return 1;
		}
		if(a[l]!=a[r]) return 0;
		l++;
		r--;
	}
	dp[s][e]=1;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0; i<m; i++){
		cin>>s>>e;
		cout<<isP(s-1,e-1)<<"\n";
	}
	return 0;
}
//14:45
// 자연수 N개 질문 M번 
// 질문 : S E (S~E 수가 팰린드롬인가?)
// 대답: Yes or No
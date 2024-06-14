#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
string s;
int dp[2501][2501],dp2[2501];
int go(int here){
	if(here == s.size()) return 0;
	
	int &ret = dp2[here];
	if(ret != INF) return ret;
	for(int i=1; i+here <= s.size(); i++){
		if(dp[here][i]) ret = min(ret,go(here+i)+1);
	}
	return ret;
}
int main(){
	cin>>s;
	for(int i=0; i<s.size(); i++) dp[i][1] = 1;
	for(int i=0; i<s.size()-1; i++){
		if(s[i]==s[i+1]){
			dp[i][2]=1;
		}
	}
	for(int i=3; i<=s.size(); i++){
		for(int j=0; j+i <= s.size(); j++){
			if(s[j]==s[j+i-1] && dp[j+1][i-2]) dp[j][i] = 1;
		}
	}
	fill(dp2,dp2+2501,INF);
	cout<<go(0)<<"\n";
	return 0;
}

// 가능한 많은 팰린드롬으로 분해 
// 문제 : 분할 시 팰린드롬이였다가 아닐 수 있음 
//        babbcbb => {bab,bcb,b} , {ba, bbcbb}
//        aabcbaaba => {aa,bcb,a,aba} , {aabcbaa,b,a} 

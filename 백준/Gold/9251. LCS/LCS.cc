#include<bits/stdc++.h> 
using namespace std;
string s1,s2;
int dp[1002][1002]; 
int main(){
	cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
	cin>>s1>>s2;
	for(int i=1; i<=s1.size(); i++){
		for(int j=1; j<=s2.size(); j++){
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}
	cout<<dp[s1.size()][s2.size()];
}
// s1의 부분수열 만들고 s2의 부분수열인지 확인?
// s1의 부분수열 2^1000 ..
// 공통 부분수열? 
// dp[i][j] -> a[1..i] 와 b[1..j]의 LCS 길이 
// dp[i-1][j] -> a[i] 가 LCS에 포함되지 않는 경우
// dp[i][j-1] -> b[j] 가 LCS에 포함되지 않는 경우
// dp[i-1][j-1] +1 -> a[i],b[j]가 모두 LCS에 포함되는 경우


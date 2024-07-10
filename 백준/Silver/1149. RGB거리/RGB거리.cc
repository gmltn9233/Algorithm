#include<bits/stdc++.h> 
using namespace std;
int n,a,b,c;
int color[3][1001];
int dp[1001][3];
int go(int idx, int prev){
	if(idx == n) return 0;
	
	int &ret = dp[idx][prev];
	if(ret) return ret;
	ret = 987654321;
	
	for(int i=0; i<3; i++){
		if(i==prev) continue;
		int now = go(idx+1,i)+color[i][idx];
		if(ret>now) ret= now;
	}
	
	return ret;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a>>b>>c;
		color[0][i]=a;
		color[1][i]=b;
		color[2][i]=c;
	}
	cout<<go(0,-1);
}

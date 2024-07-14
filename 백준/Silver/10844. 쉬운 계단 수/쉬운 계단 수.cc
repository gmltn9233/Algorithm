#include<bits/stdc++.h> 
using namespace std;
int n;
int dp[101][11];
int go(int len, int num){
	if(len == n) return 1;
	
	int &ret = dp[len][num];
	if(ret) return ret;
	
	if(num == 0){
		ret += go(len+1,num+1)%1000000000;
	}
	else if(num == 9){
		ret += go(len+1,num-1)%1000000000;
	}
	else{
		ret += go(len+1,num-1)%1000000000+go(len+1,num+1)%1000000000;
	}
	
	return ret%1000000000;
}
int main(){
	cin>>n;
	int ans = 0;
	
	for(int i=1; i<=9; i++){
		ans += go(1,i);
		ans %= 1000000000;
	}
	cout<<ans;
}

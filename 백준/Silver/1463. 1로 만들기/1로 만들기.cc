#include<bits/stdc++.h> 
using namespace std;
int n;
int dp[1000001];
int go(int num){
	if(num == 1) return 0;
	
	int &ret = dp[num];
	if(ret) return ret;
	ret = 987654321;
	
	if(num%3==0) ret = min(ret,go(num/3)+1);
	if(num%2==0) ret = min(ret,go(num/2)+1);
	ret = min(ret,go(num-1)+1);
	
	return ret;
}
int main(){
	cin>>n;
	cout<<go(n);
}

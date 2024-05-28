#include<bits/stdc++.h> 
using namespace std;
int n;
int dp[1000001];
vector<int> v;
//1000001
int goDP(int num){
	if(num==1) return 1;
	
	int &ret = dp[num];
	if(ret) return ret;
	ret = 987654321;
	
	if(num%3==0) ret = min(ret,goDP(num/3)+1);
	if(num%2==0) ret = min(ret,goDP(num/2)+1);
	if(num) ret = min(ret,goDP(num-1)+1);
	
	return ret;
}
void go(int num){
	cout<<num<<" ";
	if(num%3==0 && dp[num/3]==dp[num]-1) go(num/3);
	else if(num%2==0 && dp[num/2]==dp[num]-1) go(num/2);
	else if(num -1 >=1 && dp[num-1]==dp[num]-1) go(num-1); 
	return;
}
void go(int num);
int main() {
	cin>>n;
	dp[1]=1;
	cout<<goDP(n)-1<<'\n';
	go(n);
	return 0;
}



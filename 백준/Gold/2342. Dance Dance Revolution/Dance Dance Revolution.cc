#include<bits/stdc++.h> 
using namespace std;
int a[100001]; 
int n;
int dp[100001][5][5];
int go(int idx,int left, int right){
	if(idx == n) return 0;
	
	int &ret = dp[idx][left][right];
	if(ret!=-1) return ret;
	ret = 987654321;
	
	int num = a[idx];
	//Left
	if(left == 0) ret = min(ret,go(idx+1,num,right)+2); 
        else if(num == left) ret = min(ret,go(idx+1,num,right)+1); 
        else if(abs(left-num)==2) ret = min(ret, go(idx+1,num,right)+4); 
        else ret = min(ret,go(idx+1,num,right)+3);
	
        //Right
	if(right == 0) ret = min(ret,go(idx+1,left,num)+2);
	else if(num == right) ret = min(ret,go(idx+1,left,num)+1);
	else if(abs(right-num)==2) ret = min(ret,go(idx+1,left,num)+4);
	else ret = min(ret,go(idx+1,left,num)+3);
	
	return ret;
}
int main(){
	while(true){
		int num = 0;
		cin>>num;
		if(num==0) break;
		a[n++] = num; 
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(0,0,0)<<"\n";
}
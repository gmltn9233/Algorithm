#include<bits/stdc++.h> 
using namespace std;
int a[100001]; 
int n;
int init;
int dp[100001][5][5];
int check(int from, int to){
	if(from == 0) return 2;
	if(from == to) return 1;
	if(abs(from-to)==2) return 4;
	return 3;
}
int go(int idx,int left, int right){
	if(idx >= n) return 0;
	
	int &ret = dp[idx][left][right];
	if(ret!=-1) return ret;
	ret = 987654321;
	
	ret = min(ret, go(idx+1,a[idx],right)+check(left,a[idx]));
	ret = min(ret, go(idx+1,left,a[idx])+check(right,a[idx]));
	return ret;
}
int main(){
	while(true){
		int num = 0;
		cin>>num;
		if(num==0) break;
		a[n]=num;
		++n;
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(0,0,0)<<"\n";
}
// 중점 0, 위 1, 왼 2, 아래 3, 오른쪽 4
// 두 발이 같은 지점에 있을 수 없음(처음 제외)
// 중앙 -> 다른 지점 2
// 지점 -> 인접 지점 3
// 지점 -> 반대 지점 4
// 사용되는 최소 힘? 
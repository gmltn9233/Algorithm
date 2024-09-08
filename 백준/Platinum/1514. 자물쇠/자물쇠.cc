#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n;
int password[101],now[101];
int dp[101][10][10][10][2];
int move(int num){
	return (num<0) ? 	num+10 : num%10;
}
int go(int idx, int x, int y, int z, int flag){
	if(idx == n) return 0;
	int &ret = dp[idx][x][y][z][flag];
	if(ret != -1) return ret;
	
	if(move(now[idx]+x) == password[idx]) return ret = min(go(idx+1,y,z,0,0),go(idx+1,y,z,0,1));
	ret = 987654321;
	int _flag = flag ? 1 : -1; 
	for(int i=1; i<=3; i++){
		ret = min(ret, 1+go(idx, move(x+i*_flag),y,z,flag));
		ret = min(ret, 1+go(idx, move(x+i*_flag),move(y+i*_flag),z,flag));
		ret = min(ret, 1+go(idx, move(x+i*_flag),move(y+i*_flag),move(z+i*_flag),flag));
	}
	return ret;
}
int main() {
    cin>>n;
   	for (int i = 0; i < n; i++)scanf("%1d", &now[i]);
    for (int i = 0; i < n; i++)scanf("%1d", &password[i]);
    memset(dp,-1,sizeof(dp));
    cout<<min(go(0,0,0,0,0),go(0,0,0,0,1));
	return 0;
}

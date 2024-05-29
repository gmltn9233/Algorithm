#include<bits/stdc++.h> 
using namespace std;
int n,m1,m2,c;
int dp[10004];
int main() {
	while(true){
		scanf("%d %d.%d", &n, &m1, &m2);
        if(n == 0) break;
        int cost = 100*m1 + m2;
        fill(dp,dp+10004,0);
        for(int i=0; i<n; i++){
        	scanf("%d %d.%d", &c, &m1, &m2);
        	int p = 100*m1 + m2;
        	for(int j = p; j<= cost; j++){
        		dp[j] = max(dp[j], dp[j-p] + c);
			}
		}
		cout<<dp[cost]<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int A,B,C;
int dp[101][101][101];
int w(int a,int b, int c){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	if(a<=50 || b<=50 || c<=50) return 1;
	
	int &ret = dp[a][b][c];
	if(ret!=-1) return ret;
	
	if(a>70 || b>70 || c>70) ret=w(70,70,70);
	else if(a<b && b<c) ret=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	else ret=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	
	return ret;
}
int main(){
	memset(dp,-1,sizeof(dp));
	while(true){
		cin>>A>>B>>C;
		if(A==-1 && B==-1 && C==-1) break;
		cout<<"w("<<A<<", "<<B<<", "<<C<<") = "<<w(A+50,B+50,C+50)<<"\n";
	}	
}

#include<bits/stdc++.h> 
using namespace std;
int n,w;
int y[1004],x[1004];
int dp[1004][1004];
int cal(int a,int b){
	return abs(y[a]-y[b])+abs(x[a]-x[b]);
}
int go(int a, int b){
	if(a==w+1 || b==w+1) return 0;
	
	int &ret = dp[a][b];
	if(ret) return ret;
	
	int next = max(a,b)+1;
	ret = min(go(next,b)+cal(a,next), go(a,next)+cal(b,next));
	return ret;
}
int main(){
	cin>>n>>w;
	y[0]=1, x[0]=1;
	y[1]=n, x[1]=n;
	for(int i=2; i<=w+1; i++){
		cin>>y[i]>>x[i];
	}
	cout<<go(0,1)<<"\n";
	int a=0, b=1;
	for(int i=2; i<=w+1; i++){
		if(dp[i][b]+cal(a,i) < dp[a][i]+cal(b,i)){
			cout<<"1\n";
			a=i;
		}
		else{
			cout<<"2\n";
			b=i;
		}
	}
 	return 0;
}


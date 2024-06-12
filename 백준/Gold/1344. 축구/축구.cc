#include<bits/stdc++.h> 
using namespace std;
double a,b;
bool isP[19];
double dp[19][19][19];
double go(int idx, int x, int y){
	if(idx == 18) return (isP[x]||isP[y]) ? 1.0 : 0.0;
	
	double &ret = dp[idx][y][x];
	if(ret>-1) return ret;
	// double은 == 비교 금지 
	ret = 0.0;
	ret += go(idx+1,x,y)*(1-a)*(1-b);
	ret += go(idx+1,x+1,y)*(a)*(1-b);
	ret += go(idx+1,x,y+1)*(1-a)*b;
	ret += go(idx+1,x+1,y+1)*a*b;
	return ret;
}
void setP(){
	fill(isP,isP+20,1);
	isP[0]=0;
	isP[1]=0;
	for(int i=2; i<=20; i++){
		for(int j=i+i; j<=20; j+=i){
			isP[j]=0;
		}
	}
}
int main(){
	scanf("%lf %lf",&a,&b);
	a/=100;
	b/=100;
	setP();
	memset(dp,-1,sizeof(dp));
	printf("%.6lf",go(0,0,0));
}

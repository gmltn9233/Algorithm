#include<bits/stdc++.h>
using namespace std;
int n,b,l,r,sum,ret;
int check[4000004],a[4000004];
int main(){
	cin >>n;
	for(int i=2; i<=n; i++){
		if(check[i]){
			continue;
		}
		for(int j=i*2; j<=n; j+=i){
			check[j]=1;
		}
	}
	for(int i=2; i<=n; i++){
		if(!check[i]){
			a[b++]=i;
		}
	}
	while(true){
		if(sum>=n) sum-=a[l++];
		else if(r==b) break;
		else{
			sum += a[r++];
		}
		if(sum==n) ret++;
	}
	cout<<ret;
	return 0;
}
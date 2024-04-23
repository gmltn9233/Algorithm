#include<bits/stdc++.h>
using namespace std;
int n,ret=2;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		ret = ret-1 + ret;
	}
	cout<<ret*ret;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int ret;
int main(){
	int a,b,v,ret;
	cin>>a>>b>>v;
	v-=a;
	if(v%(a-b)) {
		ret = v/(a-b)+1;
	}
	else{
		ret =v/(a-b);
	}
	cout<<ret+1;
	return 0;
}
#include<bits/stdc++.h>
using namespace std; 
int x;
int ret=1;
int main(){
	cin>>x;
	while(x!=1){
		if(x&1) ret++;
		x/=2;
	}
	cout<<ret;
	return 0;
}

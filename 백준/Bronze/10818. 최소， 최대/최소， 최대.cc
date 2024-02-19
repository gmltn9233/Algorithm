#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int ret1=987654321,ret2=-987654321;
string s;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		ret1=min(ret1,a);
		ret2=max(ret2,a);
	}
	cout<<ret1<<" "<<ret2;
return 0;
}


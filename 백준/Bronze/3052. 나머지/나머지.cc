#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int ret1=987654321,ret2=-987654321;
int ret[105];
map<int,int> mp;
int main(){
	for(int i=0; i<10; i++){
		cin>>a;
		mp.insert({a%42,1});
	}
	cout<< mp.size();
return 0;
}


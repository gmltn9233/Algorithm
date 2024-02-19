#include<bits/stdc++.h>
using namespace std;
int main(){
	int ret[26];
	fill(ret,ret+26,-1);
	int n;
	string s;
	cin>>s;
	for(int i=0; i<s.size();i++){
		if(ret[s[i]-'a']==-1){
			ret[s[i]-'a']=i;
		}
	}
	for(int i=0; i<26;i++){
		cout<<ret[i]<<" ";
	}
return 0;
}


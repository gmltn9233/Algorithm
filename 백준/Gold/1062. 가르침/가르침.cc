#include<bits/stdc++.h>
using namespace std; 
int n,k;
string s;
int words[51];
int wordcnt(int bit){
	int cnt=0;
	for(int i=0; i<n; i++){
		if((bit & words[i])==words[i]){
			++cnt;
		}
	}
	return cnt;
}
int go(int index, int k, int mask){
	if(k<0) return 0;
	if(index == 26) return wordcnt(mask);
	int ret = go(index+1, k-1, mask|(1<<index));
	if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a'){
		ret = max(ret,go(index+1,k,mask));
	}
	return ret;
}
int main(){
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>s;
		for(char str: s){
			words[i] |= (1<<(str-'a'));
		}
	}
	cout<<go(0,k,0);
	return 0;
}

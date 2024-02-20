#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int ret[27];
int main(){
	string s;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='a'&&s[i]<='z'){
			s[i]=(s[i]-'a')+'A';
		}
		ret[s[i]-'A']++;
	}
	int cnt=0;
	for(int i=0; i<26; i++){
		cnt= max(cnt,ret[i]);
	}
	for(int i=0; i<26; i++){
		if(cnt==ret[i]){
			v.push_back(i);
		}
	}
	if(v.size()==1){
		cout<<char('A'+v[0]);
	}
	else{
		cout<<"?";
	}
return 0;
}


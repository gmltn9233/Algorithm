#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<int> st;
int ar[200005];
int ret,cnt,bfindex,bfcnt;
int main(){
	cin>>n;
	cin>>s;
	for(int i=0; i<s.size();i++){
		if(s[i]=='('){
			st.push(i);
		}
		else if (st.size()){
			ar[i]= ar[st.top()]=1;
			st.pop();
		}
	}
	for(int i=0; i<n; i++){;
		if(ar[i]){
			++cnt;
			ret=max(ret,cnt);
		}
		else{
			cnt=0;
		}
	}
	cout<<ret<<'\n';
	return 0;
}


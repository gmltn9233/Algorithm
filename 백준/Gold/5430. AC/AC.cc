#include<bits/stdc++.h>
using namespace std;
int T,n;
string p,a;
int main(){
	cin>>T;
	for(int i=0; i<T; i++){
		deque<int> ret;
		cin>>p>>n;
		cin>>a;
		int x=0;
		for(char c: a){
			if(c=='['||c==']') continue;
			if(c>='0'&&c<='9') x=x*10+c-'0';
			else{
				if(x>0) ret.push_back(x);
				x=0;
			}
		}
		if(x>0) ret.push_back(x);
		bool flag=false;
		bool error =false;
		for(char c: p){
			if(c=='R'){
				flag= !flag;
			}
			else{
				if(ret.empty()){
					error=true;
					break;
				}
				if(flag){
					ret.pop_back();
				}
				else{
					ret.pop_front();
				}
			}
		}
		if(error){
			cout<<"error"<<"\n";
		}
		else{
			cout<<"[";
			if(flag){
				reverse(ret.begin(),ret.end());
			}
			for(int i=0; i<ret.size();i++){
				cout<<ret[i];
				if(i<ret.size()-1) cout<<",";
			}
			cout<<"]"<<'\n';
		}
	}
	return 0;
}


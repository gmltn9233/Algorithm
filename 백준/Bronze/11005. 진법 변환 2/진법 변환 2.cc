#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
vector<int> v;
vector<char> ret;
int main(){
	cin>>s>>n;
	while(s>=n){
		v.push_back(s%n);
		s/=n;
	}
	v.push_back(s);
	reverse(v.begin(),v.end());
	for(int i=0; i<v.size();i++){
		if(v[i]>=10){
			ret.push_back(v[i]+'A'-10);
		}
		else{
			ret.push_back(v[i]+'0');
		}
	}
	for(int i=0; i<ret.size(); i++){
		cout<<ret[i];
	}
	return 0;
}
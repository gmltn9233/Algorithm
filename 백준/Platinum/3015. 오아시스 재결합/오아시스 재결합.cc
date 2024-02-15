#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a;
stack<pair<ll,ll>> s;
ll ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		int cnt=1;
		while(!s.empty()&&s.top().first<=a){
			if(s.top().first==a){
				cnt=s.top().second+1;
			}
			else{
				cnt =1;
			}
			ret+=s.top().second;
			s.pop();
		}
		if(!s.empty()){
			ret++;
		}
		s.push({a,cnt});
	}
	cout<<ret<<'\n';
	return 0;
}


#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,m,l,h,mid,ret;
ll a[10004];
bool check(ll mid){
	ll cnt = 0;
	for(int i=0; i<m; i++){
		cnt += mid/a[i];
		if(mid%a[i]){
			cnt ++;
		}
	}
	if(cnt>= n){
		return true;	
	}
	else{
		return false;
	}
}
int main() {
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>a[i];
	}
	if(n<=m){
		cout<< n;
	}
	else{
	l=1; h=6e10+4;
	while(l<=h){
		mid = (l+h)/(1ll*2);
		if(check(mid)){
			h = mid - 1;
			ret = mid-1;
		}
		else{
			l = mid + 1;
		}
	}
	//cout<<"ret: "<<ret<<'\n';
	ll temp = n;
	for(int i=0; i<m; i++){
		temp -= (ret/a[i]);
		if(ret%a[i]) --temp;
	}
	//cout<<"temp: "<<temp<<"\n";
	ll index = 0;
	for(int i=0; i<m; i++){
		if(ret%a[i]==0){
			--temp;
			if(temp==0){
				index = i;
			}
		}
	}
	cout<<index+1;
	}
	return 0;
}






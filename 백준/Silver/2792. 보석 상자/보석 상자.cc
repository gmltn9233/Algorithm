#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
ll n,m,a[300001],ret = 1e18;
bool check(ll mid){
	ll num = 0;
	for(int i=0; i<m; i++){
		num += a[i]/mid;
		if(a[i] % mid) num ++;
	}
	return n>=num;
}
int main(){
	cin>>n>>m;
	ll l = 1, h = 0, mid;
	for(int i=0; i<m; i++){
		cin>>a[i];
		h = max(h,a[i]);
	}
	while(l <= h){
		mid = (l+h)/2;
		if(check(mid)){
			ret = min(ret, mid);
			h = mid - 1;
		}else l = mid +1;
	}
	cout<<ret;
	return 0;
}

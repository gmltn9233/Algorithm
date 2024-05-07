#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,attack,ret,lo,hi;
ll t[123500],a[123500],h[123500];
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}   
bool go(ll maxHp){
	ll curHp = maxHp;
	ll initAttack = attack;
	for(int i=0; i<n; i++){
		if(t[i]==2){
			initAttack+=a[i];
			curHp = min(maxHp, curHp+h[i]);
		}else{
			ll cnt = h[i] / initAttack + (h[i] % initAttack ? 1 : 0); 
			curHp -= (cnt - 1) * a[i];
		}
		if(curHp <= 0){
			return false;
		}
	}
	return true;
}
int main() {
	fastIO();
	cin>> n >> attack;
	for(int i=0; i<n; i++){
		cin>>t[i]>>a[i]>>h[i];
	}
	lo=1, hi= 1e18 +4;
	while(lo<=hi){
		ll mid = (lo+hi)/2;
		if(go(mid)){
			hi = mid - 1;
			ret = mid;
		}
		else{
			lo = mid + 1;
		}
	}
	cout<<ret;
	return 0;
}



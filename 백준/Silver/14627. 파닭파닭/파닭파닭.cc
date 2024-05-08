#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll s,c,maxNum,l,h,mid,ret,sum;
ll a[1000004];
bool check(ll mid){
	ll cnt = 0;
	if(mid>maxNum){
		return false;
	}
	for(int i=0; i<s; i++){
		cnt += a[i]/mid;
	}
	if(cnt >=c){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	cin>>s>>c;
	for(int i=0; i<s; i++){
		cin>>a[i];
		maxNum = max(maxNum,a[i]);
		sum +=a[i];
	}
	l=1, h=1e9;
	while(l<=h){
		mid = (l+h)/(1LL*2);
		if(check(mid)){
			ret = mid;
			l = mid+1;
		}
		else{
			h = mid-1;
		}
	}
	cout<<sum-ret*c;
	return 0;
}



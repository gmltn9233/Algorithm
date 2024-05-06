#include<bits/stdc++.h> 
using namespace std;
int n,m,total,ret =100001,maxN;
int a[100001];
bool check(int mid){
	if(mid < maxN){
		return false;
	}
	int budget = mid;
	int cnt = 1;
	for(int i=0; i<n; i++){
		if(budget< a[i]){
			++cnt;
			budget = mid;
		}
		budget -= a[i];
	}
	if(cnt <= m){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
		total += a[i];
		maxN = max(maxN,a[i]);
	}
	int l=1,h=total,mid;
	while(l<=h){
		mid = (l+h)/2;
		if(check(mid)){
			ret = mid;
			h = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	cout<<ret;
	return 0;
}



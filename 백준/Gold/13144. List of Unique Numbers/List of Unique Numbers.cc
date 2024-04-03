#include<bits/stdc++.h>
using namespace std;
long long n,ret;
long long l,r;
long long a[100004],cnt[100004];
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%lld",a+i);
	}
	while(r<n){
		if(!cnt[a[r]]){
			cnt[a[r]]++;
			r++;
		}
		else{
			ret += r-l;
			cnt[a[l]]--;
			l++;
		}
	}
	ret += (long long)(r-l+1)*(r-l)/2;

	cout<<ret;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[16];
int n,t,p,ret; 
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>t>>p;
		
		if (i + t <= n){
			a[i + t] = max(a[i + t], a[i] + p);
		}
		
		a[i + 1] = max(a[i + 1], a[i]);
	}
	
	cout<< a[n];
	return 0;
}

// N일동안 최대한 많은 상담
// T: 기간, P: 금액
 
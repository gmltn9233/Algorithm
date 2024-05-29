#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
int n,k,temp;
ll a[10004];
int main() {
	cin>>n>>k;
	a[0]=1;
	for(int i=0; i<n; i++){
		cin>>temp;
		for(int j=temp; j<=k; j++){
			a[j] += a[j-temp];
		}
	}
	cout<<a[k];
	return 0;
}

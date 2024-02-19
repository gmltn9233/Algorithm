#include<bits/stdc++.h>
using namespace std;
double a,b,c;
int ret1=987654321,ret2=-987654321;
vector<double> v;
double mx;
map<int,int> mp;
int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		mx=max(mx,a);
		v.push_back(a);
	}
	double total=0;
	for(int i=0; i<n; i++){
		v[i]=(v[i]/mx) *100;
		total+=v[i];
	}
	printf("%lf",total/n);
	
return 0;
}


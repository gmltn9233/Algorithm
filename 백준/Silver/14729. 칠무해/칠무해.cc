#include<bits/stdc++.h>
using namespace std;
int n;
double a;
vector<double> v;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<7; i++){
		printf("%.3lf",v[i]);
		cout<<'\n';
	}
	return 0;
}
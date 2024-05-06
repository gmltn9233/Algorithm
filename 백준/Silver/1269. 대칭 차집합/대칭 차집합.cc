#include<bits/stdc++.h> 
using namespace std;
int n,m,temp,ret;
map<int,int> a;
int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>temp;
		a[temp]++;
	}
	for(int i=0; i<m; i++){
		cin>>temp;
		a[temp]++;
	}
	for(auto it : a){
		if(it.second == 1){
			++ret;
		}
	}
	cout<<ret;
	return 0;
}



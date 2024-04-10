#include<bits/stdc++.h>
using namespace std;
int n;
int c[21][21];
int ret =987654321;
int go(vector<int>&a, vector<int>&b){
	pair<int,int> ret;
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n/2; j++){
			if(i==j) continue;
			ret.first += c[a[i]][a[j]];
			ret.second += c[b[i]][b[j]];
		}
	}
	return abs(ret.first - ret.second);
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>c[i][j];
		}
	}
	for(int i=0; i<(1<<n);i++){
		if(__builtin_popcount(i)!= n/2 )continue;
		vector<int> star,link;
		for(int j=0; j<n; j++){
			if(i&(1<<j)){
				star.push_back(j);
			}
			else{
				link.push_back(j);
			}
		}
		ret = min(ret,go(star,link));
	}
	cout<<ret;
	return 0;
}
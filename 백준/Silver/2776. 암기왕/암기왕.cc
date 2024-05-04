#include<bits/stdc++.h>
using namespace std; 
int t,n,m;
int check(int num, vector<int> &v){
	int l=0, r=v.size()-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(v[mid]==num) return 1;
		else if(v[mid]<num){
			l = mid+1;
		}
		else{
			r= mid-1;
		}
	}
	return 0;
}
int main(){
	cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
	cin>>t;
	for(int i=0; i<t; i++){
		vector<int> v;
		int num = 0;
		cin>>n;
		for(int j=0; j<n; j++){
			cin>>num;
			v.push_back(num);
		}
		sort(v.begin(),v.end());
		cin>>m;
		for(int j=0; j<m; j++){
			cin>>num;
			cout<<check(num,v)<<"\n";
		}
	}
	return 0;
}

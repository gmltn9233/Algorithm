#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P v[1000004];
int n, from,to,ret,l,r;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>from>>to;
		v[i]=P(from,to);
	}
	sort(v,v+n);
	l = v[0].first;
	r = v[0].second;
	for(int i=1; i<n; i++){
		if(r < v[i].first){
			ret += abs(r-l);
			l = v[i].first;
			r = v[i].second;
		}
		else if(v[i].first<= r && v[i].second >= r){
			r = v[i].second;
		}
	}
	ret += abs(r-l);
	cout<<ret<<'\n';
}
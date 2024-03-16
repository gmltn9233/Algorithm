#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P v[1000004];
int n, from,to,ret;
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
	from = v[0].first;
	to = v[0].second;
	for(int i=1; i<n; i++){
		if(to < v[i].first){
			ret += abs(to-from);
			from = v[i].first;
			to = v[i].second;
		}
		else if(v[i].first<= to && v[i].second >= to){
			to = v[i].second;
		}
	}
	ret += abs(to-from);
	cout<<ret<<'\n';
	return 0;
}
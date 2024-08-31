#include<bits/stdc++.h> 
using namespace std;
int t,n,x,y;
vector<int> tree,_y;
vector<pair<int,int>> a;
int sum(int idx){
	int ret = 0;
	while(idx>0){
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}
void update(int i, int value){
	int idx = i;
	while(idx <=n){
		tree[idx] += value;
		idx += (idx & -idx);
	}
	return;
}
int find_index(int value){
	int l=0, r=_y.size()-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(_y[mid] == value) return mid;
		if(_y[mid] < value) l = mid+1;
		else r = mid - 1;
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		a.clear();
		_y.clear();
		tree.clear();
		tree.resize(n+1);
		for(int i=0; i<n; i++){
			cin>>x>>y;
			a.push_back({x,y*-1});
			_y.push_back(y*-1);
		}
		sort(a.begin(),a.end());
		sort(_y.begin(),_y.end());
		long long ret = 0;
		update(find_index(a[0].second)+1,1);
		for(int i=1; i<n; i++){
			int idx = find_index(a[i].second)+1;
			int num = ret;
			ret += sum(idx);
			update(idx,1);
		}
		cout<<ret<<"\n";
	}
 	return 0;
} 

 

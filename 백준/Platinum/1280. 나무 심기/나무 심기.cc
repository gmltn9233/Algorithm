#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int max_n = 200004;
const ll mod = 1e9+7;
ll ret = 1;
vector<ll> tree_cnt(max_n,0),tree_sum(max_n,0);
int n,value;

ll _sum(vector<ll> &tree, int idx){
	ll _ret = 0;
	int i = idx;
	while(i){
		_ret += tree[i];
		i-=(i&-i);
	}
	return _ret;
}

ll sum(vector<ll> &tree, int s, int e){
	if(s>e) return 0;
	return (_sum(tree,e)-_sum(tree,s-1));
}
void update(vector<ll> &tree,int idx, ll value){
	int i = idx;
	while(i<=max_n){
		tree[i] += value;
		i += (i&-i);
	}
	return;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>value; value++;
		if(i!=0){
			ll left = value*sum(tree_cnt,1,value-1) - sum(tree_sum,1,value-1);
			ll right = sum(tree_sum,value+1, max_n) - value*sum(tree_cnt,value+1,max_n);
			ret *= (left+right) % mod;
			ret %= mod;
		}
		update(tree_cnt,value,1);
		update(tree_sum,value,value);
	}
	cout<<ret;
	return 0;
}

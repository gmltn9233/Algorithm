#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, x, y, t;
vector<int> tree, _y;
vector<pair<int, int>> a;

// 펜윅트리 합 
int sum (int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
// 펜윅트리 업데이트  
void update(int pos, int value){
    int idx = pos;
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
    return;
}
int find_index(int value){
    int lo = 0, hi = _y.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(_y[mid] == value) return mid;
        if(_y[mid] < value) lo = mid + 1;
        else hi = mid - 1;
    }
}
int main() {
    cin >>t;
    while(t--){
    	cin >> n;
		tree.clear();
    	_y.clear();
    	a.clear();
    	tree.resize(n+1);
        
        for(int i=0; i<n; i++){
        	cin>>x>>y;
        	a.push_back({x,-1*y});
        	_y.push_back(-1*y);
		}
		sort(a.begin(),a.end());
		sort(_y.begin(),_y.end());
		ll ret = 0;
		update(find_index(a[0].second)+1,1);
		for(int i=1; i<n; i++){
			int idx = find_index(a[i].second)+1;
			ret += sum(idx);
			update(idx,1);
		}
		cout<<ret<<"\n";
    }
	return 0;
}

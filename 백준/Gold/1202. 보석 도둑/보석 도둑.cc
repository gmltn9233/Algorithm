#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k;

    vector<pair<ll,ll>> gem; gem.reserve(n);      // {weight, value}
    for (int i = 0; i < n; ++i) {
        ll m, v; cin >> m >> v;
        gem.emplace_back(m, v);
    }
    sort(gem.begin(), gem.end());                 // weight asc

    vector<ll> bag; bag.reserve(k);
    for (int i = 0; i < k; ++i) {
        ll c; cin >> c; bag.push_back(c);
    }
    sort(bag.begin(), bag.end());                 // capacity asc

    priority_queue<ll> pq;                        // values max-heap
    ll ret = 0;
    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (j < n && gem[j].first <= bag[i])   // fit this bag
            pq.push(gem[j++].second);
        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
        }
    }
    cout << ret << '\n';
    return 0;
}
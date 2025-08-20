#include <bits/stdc++.h>
using namespace std;
int n,k,m,v,cnt;
long long c,ret;
vector<pair<int,int>> jewels;
multiset<long long> bags;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>m>>v;
        jewels.push_back({v,m});
    }
    
    sort(jewels.begin(), jewels.end());
    reverse(jewels.begin(), jewels.end());
    
    for(int i=0; i<k; i++){
        cin>>c;
        bags.insert(c);
    }
    
    
    
    for(int i=0; i<jewels.size(); i++){
        if(cnt>k) break;
        auto it = bags.lower_bound(jewels[i].second);
        if(it != bags.end()){
            bags.erase(it);
            ++cnt;
            ret += jewels[i].first;
        }
    }
    
    cout<<ret;
    // 가격순 정렬해서 무게와 가장 근접한거로 담기
    return 0;
}
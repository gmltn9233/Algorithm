#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
int n,d,p,ret;
vector<P> a;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>p>>d;
		a.push_back({d,p});
	}
	sort(a.begin(),a.end());
	for(int i=0; i<n; i++){
		pq.push(a[i].second);
		if(pq.size()>a[i].first){
			pq.pop();
		}
	}
	while(pq.size()){
		ret+=pq.top();
		pq.pop();
	}
	cout<<ret<<"\n";
}
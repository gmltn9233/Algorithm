#include<bits/stdc++.h>
using namespace std;
int n,k,ret;
int a[101],b[101];
vector<pair<int,int>> c;
vector<pair<int,int>> d;
priority_queue<pair<int,int>> pq;
int main(){
	cin>>n>>k;
	for(int i=0; i<k; i++){
		cin>>a[i];
	}
	for(int i=0; i<k; i++){
		c.clear();
		while(pq.size()){
			c.push_back({pq.top().first-1,pq.top().second});
			//cout<<"{"<<pq.top().first<<","<<pq.top().second<<"}\n";
			pq.pop();
		}
		for(int j=0; j<c.size();j++){
			pq.push({c[j].first,c[j].second});
			//cout<<"{"<<c[j].first<<","<<c[j].second<<"}\n";
		}
		int len = 987654321;
		for(int j=i+1; j<k; j++){
			if(a[i]==a[j]){
				len = j-i;
				break;
			}
		}
		if(b[a[i]]){ //같다면 갱신 
			d.clear();
			while(pq.size()){
				d.push_back({pq.top().first,pq.top().second});
				//cout<<"{"<<pq.top().first<<","<<pq.top().second<<"}\n";
				pq.pop();
			}
			for(int j=0; j<d.size(); j++){
				if(d[j].second==a[i]){
					d[j].first = len;
				}
				pq.push({d[j].first,d[j].second});
				//cout<<"{"<<d[j].first<<","<<d[j].second<<"}\n";
			}
		}
		//cout<<"i: "<<i<<'\n';
		//cout<<"len: "<<len <<'\n';
		if(!b[a[i]]){
			if(pq.size()>=n){
				b[pq.top().second]=0;
				//cout<<"pop: "<<pq.top().second<<'\n';
				pq.pop();
				++ret;
			}
			pq.push({len,a[i]});
			b[a[i]]=1;
			//cout<<"push: "<<a[i]<<"\n";
		}
	}
	cout<<ret;
	return 0;
}
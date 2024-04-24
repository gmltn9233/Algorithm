#include<bits/stdc++.h>
using namespace std;
int n,l,s,e,endPoint,ret;
vector<pair<int,int>> v;
int main(){
	cin>>n>>l;
	for(int i=0; i<n; i++){
		cin>>s>>e;
		v.push_back({s,e});
	}
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++){
		//cout<<v[i].first<<","<<v[i].second<<"\n";
		if(v[i].second < endPoint) continue;
		else if (v[i].second >= endPoint && v[i].first < endPoint){
			int num = v[i].second - endPoint;
			ret += (num)/l + (num%l ? 1 : 0);
			endPoint += l*((num/l) + (num%l ? 1 : 0));
			//cout<<"case1\n";
		}
		else{
			int num = v[i].second - v[i].first;
			ret += num/l + (num%l ? 1 : 0);
			endPoint =v[i].first + l*((num/l)+ (num%l ? 1 : 0));
			//cout<<"case2\n";
		}
		//cout<<"endPoint: "<<endPoint<<'\n';
		//cout<<"ret: "<<ret<<"\n";
	}
	cout<<ret;
	return 0;
}
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,c;
ll a[31],ret;
vector<int> v,v2;
void go(int here , int _n, vector<int> &v, int sum){
	if(sum>c) return;
	if(here > _n){
		v.push_back(sum);
		return;
	}
	go(here+1, _n, v, sum+a[here]);
	go(here+1, _n, v, sum);
	
	return;
} 
int main(){
	cin>>n>>c;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	// 0~n/2 탐색 
	go(0,n/2-1,v,0);
	// n/2 ~ n-1 탐색 
	go(n/2,n-1,v2,0);
	// sorting
	sort(v.begin(),v.end());
	sort(v2.begin(),v2.end());
	
	for(int b : v){
		if(c-b >=0) ret += ((int)(upper_bound(v2.begin(),v2.end(),c-b)-v2.begin()));
	}
	cout<<ret<<"\n";
	return 0;
}
// 완탐? 2^30 -> 10억 
// dp? 무게 최댓값이 너무 커서 배열에 담지 못한다.
// 어떻게 해야할까? 

// Meet in the middle
// N이 너무나 클때 N을 반으로 쪼개서 N/2 기반 완탐하는것! 
// 
#include<bits/stdc++.h> 
using namespace std;
int n,num;
int lis[1000004],len;
pair<int,int> ans[1000004];
stack<int> stk;
int main() {
	fill(lis,lis+1000004,1e9+4);
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%d",&num);
		auto lowerPos =  lower_bound(lis,lis+len,num);
		int _pos = (int)(lower_bound(lis,lis+len,num)-lis);
		if(*lowerPos == 1e9+4) len ++;
		*lowerPos = num;
		ans[i].first = _pos;
		ans[i].second = num;
	}
	cout<<len<<'\n';
	for(int i=n-1; i>= 0; i--){
		if(ans[i].first == len -1){
			stk.push(ans[i].second); len--;
		}
	}
	while(stk.size()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return 0;
}






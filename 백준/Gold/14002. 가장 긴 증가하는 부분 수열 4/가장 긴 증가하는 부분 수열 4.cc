#include<bits/stdc++.h> 
using namespace std;
int n;
int lis[1004],len,num;
pair<int,int> p[1004];
stack<int> stk;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num;
		auto lower_pos = lower_bound(lis,lis+len,num);
		int pos = (int)(lower_bound(lis,lis+len,num)-lis);
		if(*lower_pos == 0) len ++;
		*lower_pos = num;
		p[i].first = pos;
		p[i].second = num;
	}
	cout<<len<<'\n';
	for(int i=n-1; i>=0; i--){
		if(p[i].first == len-1){
			stk.push(p[i].second);
			len--;
		}
	}
	while(stk.size()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	return 0;
}





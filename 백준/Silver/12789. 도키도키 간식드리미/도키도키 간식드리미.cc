#include<bits/stdc++.h>
using namespace std;
int n,cnt=1;
int a;
stack<int> s;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		//cout<<a<<"\n";
		//cout<<"cnt: "<<cnt<<'\n';
		if(a==cnt){
			++cnt;
			continue;
			//cout<<"++cnt\n";
		}
		while(s.size()){
			if(s.top()==cnt){
				s.pop();
				++cnt;
			}
			else{
				break;
			}
		}
		s.push(a);
	}
	while(s.size()){
		if(s.top()==cnt){
			s.pop();
			++cnt;
		}
		else{
			cout<<"Sad";
			break;
		}
	}
	if(!s.size()){
		cout<<"Nice";
	}
	return 0;
}
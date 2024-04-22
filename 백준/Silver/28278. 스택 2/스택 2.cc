#include<bits/stdc++.h>
using namespace std;
int n,num1,num2;
stack<int> s;
int main(){
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>> num1;
		if(num1 == 1){
			cin >> num2;
			s.push(num2);
		}
		else if(num1 == 2){
			if(s.size()){
				cout<<s.top()<<'\n';
				s.pop();
			}
			else{
				cout<<"-1\n";
			}
		}
		else if(num1 == 3){
			cout<<s.size()<<'\n';
		}
		else if(num1 == 4){
			if(s.empty()){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if(num1 == 5){
			if(s.size()){
				cout<<s.top()<<'\n';
			}
			else{
				cout<<"-1\n";
			}
		}
		else{
			continue;
		}
	}
	return 0;
}
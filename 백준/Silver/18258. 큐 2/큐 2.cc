#include<bits/stdc++.h>
using namespace std;
int n;
long long back;
string s;
queue<long long> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s;
		if(s[0]=='p'&&s[1]=='u'){
			long long num;
			cin>>num;
			q.push(num);
			back= num;
		}
		else if(s[0]=='p'){
			if(!q.size()){
				cout<<"-1\n";
			}
			else{
				cout<<q.front()<<'\n';
				q.pop();	
			}
		}
		else if(s[0]=='s'){
			cout<<q.size()<<'\n';
		}
		else if(s[0]=='e'){
			if(!q.size()){
				cout<<"1\n";
			}
			else{
				cout<<"0\n";
			}
		}
		else if(s[0]=='f'){
			if(!q.size()){
				cout<<"-1\n";
			}
			else{
				cout<<q.front()<<'\n';
			}
		}
		else if(s[0]=='b'){
			if(!q.size()){
				cout<<"-1\n";
			}
			else{
				cout<<back<<'\n';
			}
		}
		else{
			continue;
		}
	}
	return 0;
}
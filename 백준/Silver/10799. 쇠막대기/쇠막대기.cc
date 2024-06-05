#include<bits/stdc++.h> 
using namespace std;
string str;
stack<pair<char,int>> s;
int ret;
int main() {
	cin>>str;
	int cnt = 0;
	for(char c : str){
		if(c==')'){
			if(s.top().first == '('){
				if(s.top().second == cnt-1){
					s.pop();
					ret +=s.size();
				}
				else{
					s.pop();
					++ret;
				}
			}
			else{
				s.push({c,cnt});
			}
		}
		else{
			s.push({c,cnt});
		}
		cnt++;
	}
	cout<<ret;
	return 0;
}


#include<bits/stdc++.h> 
using namespace std;
string s;
int main(){
	while(true){
		int ret = 0;
		getline(cin,s);
		if(s[0]=='#') break;
		for(char c : s){
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') ++ret;
			if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U') ++ret;
		}
		cout<<ret<<"\n";
	}
}

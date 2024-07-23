#include<bits/stdc++.h> 
using namespace std;
string s;
int ret;
int main(){
	cin>>s;
	for(char c : s){
		if(c>='0' && c<='9') ret +=c-'0';
		else ret +=c-'A'+10;
		ret *=16;
	}
	cout<<ret/16;
}

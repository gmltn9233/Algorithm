#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=false;
int main(){
	cin>>s;
	for(int i=0; i<s.size();i++){
		if(i+1<s.size()&& s.substr(i,2)=="pi"||s.substr(i,2)=="ka"){
			i+=1;
		}
		else if (i+2<s.size()&&s.substr(i,3)=="chu") i+=2;
		else{
			flag=true;
		}
	}
	string ret = flag==true? "NO":"YES";
	cout<<ret;
	return 0;
}


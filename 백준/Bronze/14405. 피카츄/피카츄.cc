#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=false;
int main(){
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='p'){
			if(i+1<s.size()){
				if(s[i+1]!='i'){
					flag=true;
				}
				i++;
			}
			else{
				flag=true;
			}
		}
		else if(s[i]=='k'){
			if(i+1<s.size()){
				if(s[i+1]!='a'){
					flag=true;
				}
				i++;
			}
			else{
				flag=true;
			}
		}
		else if(s[i]=='c'){
			if(i+2<s.size()){
				if(s[i+1]!='h'||s[i+2]!='u'){
					flag=true;
				}
				i+=2;
			}
			else{
				flag=true;
			}
		}
		else{
			flag=true;
		}
	}
	string ret = flag==true? "NO": "YES";
	cout<<ret;
	return 0;
}


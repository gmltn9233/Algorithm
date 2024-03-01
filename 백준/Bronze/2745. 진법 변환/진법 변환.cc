#include<bits/stdc++.h>
using namespace std;
string s;
int a[37];
int n,ret;
int main(){
	cin>>s>>n;
	reverse(s.begin(),s.end());
	for(int i=0; i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z'){
			ret+=pow(n,i)*(s[i]-'A'+10);
		}
		else{
			ret+=pow(n,i)*(s[i]-'0');
		}
	}
	cout<<ret;
	return 0;
}
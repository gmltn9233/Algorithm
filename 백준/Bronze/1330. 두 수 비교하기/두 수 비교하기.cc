#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	if(a==b){
		cout<<"==";
	}
	else{
		char c=a>b? '>':'<';
		cout<< c;
	}
return 0;
}


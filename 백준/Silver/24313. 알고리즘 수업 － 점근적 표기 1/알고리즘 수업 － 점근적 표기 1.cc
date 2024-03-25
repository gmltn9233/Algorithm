#include<bits/stdc++.h>
using namespace std;
int a1,a0,c,n0;
int main(){
	cin>>a1>>a0;
	cin>>c;
	cin>>n0;
	if(a1*n0+a0<=c*n0&&a1 <= c){
		cout<< 1;
	}
	else{
		cout<<0;
	}
	return 0;
}


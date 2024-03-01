#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int a=1,ret=1,i=1;
	while(n>a){
		a+=i*6;
		ret++;
		i++;
	}
	cout<<ret;
	return 0;
}
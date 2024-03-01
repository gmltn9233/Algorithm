#include<bits/stdc++.h>
using namespace std;
int n,a;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		int q=0,d=0,c=0,p=0;
		q=a/25;
		a-=q*25;
		d=a/10;
		a-=d*10;
		c=a/5;
		a-=c*5;
		p=a;
		cout<<q<<" "<<d<<" "<<c<<" "<<p<<'\n';
	}
	return 0;
}
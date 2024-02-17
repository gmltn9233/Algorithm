#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int ret;
pair<int,int> countSame(int a, int b, int c){
	pair<int,int> d;
	d.first=0;
	d.second=0;
	if(a==b){
		d.first+=2;
		d.second=a;
	};
	if(a==c){
		d.first+=2;
		d.second=a;
	}
	if(b==c){
		d.first+=2;
		d.second=c;
	}
	return d;
}
int main(){
	cin>>a>>b>>c;
	pair<int,int> cnt= countSame(a,b,c);
	if(cnt.first==6){
		ret=10000+a*1000;
	}
	else if(cnt.first==2){
		ret=1000+cnt.second*100;
	}
	else{
		int maxnum= max(a,b);
		maxnum=max(maxnum,c);
		ret=100*maxnum;
	}
	cout<<ret;
return 0;
}


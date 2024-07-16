#include<bits/stdc++.h> 
using namespace std;
int n,a[1001];
int l[1001],r[1001];
int ret;
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		int num = a[i];
		for(int j=0; j<i; j++){
			if(num>a[j]) l[i]=max(l[i],l[j]+1);
		}
	}
	for(int i=n-1; i>=0; i--){
		int num = a[i];
		for(int j=n-1; j>i; j--){
			if(num>a[j]) r[i]=max(r[i],r[j]+1);
		}
	}
	for(int i=0; i<n; i++){
		//cout<<"idx: "<<i<<"\n";
		//cout<<"l: "<<l[i]<<" r:"<<r[i]<<"\n";
		int num = l[i]+r[i]+1;
		ret = max(ret,num);
	}
	cout<<ret;
}

#include<bits/stdc++.h> 
using namespace std;
int n,m,sum,ret=987654321;
int maxNum;
int a[100001];
bool check(int mid){
	if(mid<maxNum){
		return false;
	}
	//cout<<"mid: "<<mid<<'\n';
	int total = 0;
	int cnt = 0;
	for(int i=0; i<n; i++){
		//cout<<"a[i]: "<<a[i]<<"\n";
		total += a[i];
		//cout<<"total: "<<total<<"\n";
		if(total == mid){
			cnt ++;
			total = 0;
		}
		else if(total > mid){
			cnt ++;
			total = a[i];
		}
		//cout<<"cnt: "<<cnt<<"\n";
	}
	if(total>0) cnt++;
	//cout<<"cnt: "<<cnt<<"\n";
	if(cnt <= m){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
		maxNum = max(maxNum,a[i]);
	}
	int l=1,r=sum;
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)){
			ret = min(ret,mid);
			r =mid-1;
		}else{
			l= mid+1;
		}
	}
	cout<<ret;
	return 0;
}



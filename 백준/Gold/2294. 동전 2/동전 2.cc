#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
int n,k,temp;
int a[10004];
int main() {
	cin>>n>>k;
	fill(a,a+10004,INF);
	a[0]=0;
	for(int i=0; i<n; i++){
		cin>>temp;
		for(int j=temp; j<=k; j++){
			a[j] = min(a[j],a[j-temp]+1);
		}
	}
	if(a[k]==INF){
		cout<<-1<<"\n";
	}else{
		cout<<a[k]<<"\n";
	}
	return 0;
}

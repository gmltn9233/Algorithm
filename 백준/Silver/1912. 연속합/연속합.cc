#include<bits/stdc++.h>
using namespace std;
int n,ret=-1001,sum,num; 
int main(){
	cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
	 cin>>n;
	 for(int i=0; i<n; i++){
	 	cin >> num;
	 	sum +=num;
	 	ret = max(ret, sum);
	 	if(sum<0) sum = 0;
	 }
	 cout<<ret;
	return 0;
}

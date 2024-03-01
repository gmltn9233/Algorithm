#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int index=0;
	int cnt=0;
	int a,b;
	bool flag=true;
	while(flag){
		index++;
		for(int i=1; i<=index; i++){
			++cnt;
			if(cnt==n){
				if(index%2==0){
					a=i;
					b=(index+1-i);
				}
				else{
					a=(index+1-i);
					b=i;
				}
				flag=false;;
			}
		}
	}
	cout<<a<<"/"<<b;
	return 0;
}
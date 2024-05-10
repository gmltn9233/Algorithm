#include<bits/stdc++.h> 
using namespace std;
int n;
int lis[1004],len,num;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>num;
		auto lower_pos = lower_bound(lis,lis+len,num);
		if(*lower_pos == 0) len ++;
		*lower_pos = num;
	}
	cout<<len;
	return 0;
}






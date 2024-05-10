#include<bits/stdc++.h> 
using namespace std;
int n;
double a[10004],sum=1,ret;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum *= a[i];
		if(sum < a[i]){
			sum = a[i];
		}
		ret = max(ret,sum);
	}
	printf("%.3lf",ret);
	return 0;
}






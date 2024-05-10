#include<bits/stdc++.h> 
using namespace std;
int n;
double a[10004],b[10004],ret;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<n; i++){
		double sum = 1;
		for(int j=i; j<n; j++){
			sum *= a[j];
			ret = max(sum,ret);
		}
	}
	printf("%.3lf",ret);
	return 0;
}






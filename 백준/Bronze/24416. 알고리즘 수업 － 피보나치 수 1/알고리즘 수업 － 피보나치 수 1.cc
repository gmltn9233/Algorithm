#include<bits/stdc++.h> 
using namespace std;
int n;
int f[41];
int ret1,ret2;
int fib(int a){
	if(a==1 || a==2){
		++ret1;
		return 1;
	}
	else return (fib(a-1)+fib(a-2));
}
int fibonacci(int a){
	for(int i=3; i<=a; i++){
		f[i]=f[i-1]+f[i-2];
		++ret2;
	}
	return f[a];
}
int main(){
	cin>>n;
	int num1 = fib(n);
	int num2 =fibonacci(n);
	cout<<ret1<<" "<<ret2<<"\n";
}

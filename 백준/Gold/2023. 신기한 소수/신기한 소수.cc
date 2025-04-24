/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v;
bool isPrime(long long n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3; i*i*(long long)1 <=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}

void go(long long num,int cnt){
    if(cnt == n){
        v.push_back(num);
        return;
    }
    for(int i=0; i<=9; i++){
        if(isPrime(10*num + i)){
            go(10*num+i, cnt+1);
        }
    }
    return;
}

int main()
{
    cin>>n;
    
    go(0,0);
    for(long long num : v){
        cout<<num<<"\n";
    }
    return 0;
}
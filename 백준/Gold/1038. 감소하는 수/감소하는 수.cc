/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,idx;
vector<long long> v;
void go(long long num){
    v.push_back(num);
    int last = num % 10;
    for(int i=last-1; i>=0; i--){
        go(num*10+i);
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<=9; i++){
        go(i);
    }
    
    sort(v.begin(),v.end());
    
    if(n>=v.size()){
        cout<<-1;
    }
    else{
        cout<<v[n];
    }
    
    
    return 0;
}


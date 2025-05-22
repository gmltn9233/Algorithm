/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;

void change(int s, int e, string& str){
    for(int i=s; i<=e; i++){
        str[i] = ' ';
    }
}

void divide(int s, int e, string& str){
    if(s==e) return;
    int len = (e - s + 1);
    int third = len / 3;
    int ds = s + third;
    int de = s + 2 * third - 1;
    change(ds,de,str);
    divide(s,ds-1,str);
    divide(de+1,e,str);
}

void solve(int n){
    string str = "";
    int num = 1;
    for(int i=0; i<n; i++){
        num *= 3;
    }
    for(int i=0; i<num; i++){
        str+='-';
    }
    int s = 0, e = num-1;
    divide(s,e,str);
    cout<<str<<"\n";
}
int main()
{
    while(cin>>n){
        solve(n);
    }
    return 0;
}
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int b;
string s;
long long go(int n, int b){
    long long ret = 1;
    for(int i=0; i<n-1; i++){
        ret *= b;
    }
    return ret;
}
int main()
{
    cin>>s>>b;
    long long ret = 0;
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            ret += (s[i]-'0')*go(s.size()-i,b);
        }
        else{
            ret += (s[i]-'A'+10)*go(s.size()-i,b);
        }
        
    }
    
    cout<<ret;
    return 0;
}
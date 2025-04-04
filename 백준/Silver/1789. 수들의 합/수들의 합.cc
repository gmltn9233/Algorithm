#include <bits/stdc++.h>
using namespace std;

long long s, ret=1;
int main()
{
    cin >> s;
   for(long long i = 1; i<=s; i++){
       long long num = (long long)i*(i+1)/2;
       if(num>s){
           ret = i-1;
           break;
       }
   }
    cout<<ret;
    return 0;
}
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
long long num;
vector<long long> v;
long long ret;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        auto it = lower_bound(v.begin(),v.end(), num);
        if(it == v.end()) v.push_back(num);
        else *it = num;
    }
    
    cout<<v.size();
    
    return 0;
}
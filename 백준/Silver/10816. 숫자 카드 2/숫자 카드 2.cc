/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,m;
long long num;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>num;
        cout<<upper_bound(v.begin(),v.end(),num)-lower_bound(v.begin(),v.end(),num)<<" ";
    }
    

    return 0;
}
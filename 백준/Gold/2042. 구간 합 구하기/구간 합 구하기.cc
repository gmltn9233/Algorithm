/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long tree[1000004];
long long arr[1000004];
int n,m,k;
long long a,b,c,num;
void update(int idx, long long num){
    while(idx<=n){
        tree[idx] += num;
        idx += (idx & -idx);
    }
}

long long sum(int idx){
    long long result = 0;
    while(idx>0){
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        cin>>num;
        arr[i]=num;
        update(i,num);
    }
    for(int i=0; i<m+k; i++){
        cin>>a>>b>>c;
        if(a==1){
            long long diff = c - arr[b];
            arr[b] = c;
            update(b,diff);
        }else{
            cout<<sum(c)-sum(b-1)<<"\n";
        }
    }
    return 0;
}
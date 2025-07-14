/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,p,a,b,ret;
priority_queue<int,vector<int>,less<int>> pq[7];
int main()
{
    cin>>n>>p;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        while(pq[a].size()){
            int top = pq[a].top();
            if(top>b){
                pq[a].pop();
                ++ret;
            }else{
                break;
            }
        }
        if(pq[a].size() && pq[a].top()==b) continue;
        pq[a].push(b);
        ++ret;
    }
    cout<<ret;
    return 0;
}
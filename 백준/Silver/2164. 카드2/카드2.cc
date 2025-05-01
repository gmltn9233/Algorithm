/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> dq;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }
    while(true){
        // for(int i=0; i<dq.size(); i++){
        //     cout<<dq[i]<<" ";
        // }
        //cout<<"\n";
        if(dq.size()==1) break;
        dq.pop_front();
        int front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }
    cout<<dq[0];
    return 0;
}
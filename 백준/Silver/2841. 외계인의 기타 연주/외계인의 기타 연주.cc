/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,p,a,b,ret;
stack<int> st[7];
int main()
{
    cin>>n>>p;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        // pq[a]가 빈 큐가 아닐 때
        while(st[a].size()){
            int top = st[a].top();
            // 우선순위 큐의 top(최댓값) 이 
            // 현재 값 보다 크다면 손가락을 뗌
            if(top>b){
                st[a].pop();
                ++ret;
            }
            // 현재 값 보다 작다면 break;
            else{
                break;
            }
        }
        // 최댓값이 같은 값이라면 손가락 안떼도 됨
        if(st[a].size() && st[a].top()==b) continue;
        // 아닐 경우 새 손가락 추가
        st[a].push(b);
        ++ret;
    }
    cout<<ret;
    return 0;
}


// n -> 탐색 요청 수
// p -> 

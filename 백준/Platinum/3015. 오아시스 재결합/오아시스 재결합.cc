/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
long long n,ret;
long long num;
vector<long long> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    stack<pair<long long, long long>>st;
    for(int i=0; i<n; i++){
        cin>>num;
        int cnt = 1;
        while(st.size() && st.top().first <= num){
            if(st.top().first == num){
                cnt = st.top().second+1;
            }else{
                cnt = 1;
            }
            ret += st.top().second;
            st.pop();
        }
        if(st.size()){
            ret++;
        }
        st.push({num,cnt});
    }    
    cout<<ret;

    
    return 0;
}

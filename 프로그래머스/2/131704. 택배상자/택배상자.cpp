#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    stack<int> st;
    int now = 1;
    int idx = 0;
    int answer = 0;
    while(true){
        if(idx==order.size() || now == order.size()+1) break;
        
        if(order[idx]==now){
            idx++;
            answer++;
            now++;
        }else{
            if(st.size()==0){
                st.push(now);
                now++;
            } 
            else{
                if(st.top()==order[idx]){
                    st.pop();
                    idx++;
                    answer++;
                }else{
                    st.push(now);
                    now++;
                }
            }
        }
    }
    while(st.size()){
        if(st.top()==order[idx]){
            st.pop();
            idx++;
            answer++;
        }else{
            break;
        }
    }
    
    return answer;
}
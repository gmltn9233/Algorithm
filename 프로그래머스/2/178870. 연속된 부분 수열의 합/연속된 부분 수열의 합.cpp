#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int min_size = 987654321;
    int bestl=0;
    int bestr=0;
    int l = 0;
    int r = 0;
    int sum = sequence[0];
    while(l < sequence.size() && r < sequence.size()){
        if(sum == k){
            int now_size = r-l+1;
            if(min_size > now_size){
                bestl=l;
                bestr=r;
                min_size = now_size;
            }
            sum -= sequence[l];
            ++l;
        }
        else if(sum > k){
            sum -= sequence[l];
            l++;
        }
        else{
            r++;
            sum += sequence[r];
        }
    }
    
    answer.push_back(bestl);
    answer.push_back(bestr);
    
    return answer;
}
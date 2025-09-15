#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int max_diff = 0;
    for(auto diff : diffs){
        max_diff = max(diff,max_diff);
    }
    int l = 1, r = max_diff;
    while(l<=r){
        int mid = (l+r)/2;
        int prev_time = 0;
        long long total = 0;
        for(int i=0; i<diffs.size(); i++){
            if(mid < diffs[i]){
                total += (diffs[i]-mid)*(prev_time + times[i]) + times[i];
            }else{
                total += times[i];
            }
            prev_time = times[i];
        }
        if(limit < total){
            l = mid+1;
        }else{
            r = mid-1;
        }
        answer = l;
    }
    return answer;
}




// diff <= level -> time_cur 소모
// diff > level -> (diff-level)*(time_prev + time_cur) + time_cur 소모
// limit 이내에 퍼즐을 해결하기 위한 숙련도의 최솟값 구하기
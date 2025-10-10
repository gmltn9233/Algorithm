#include <bits/stdc++.h>

using namespace std;
int maxDiff = 0;
vector<int> answer;
void dfs(int idx, int arrows, vector<int> &ryan, vector<int> &apeach){
    // 종료 조건
    if(idx == 11 || arrows == 0){
        if (arrows>0) ryan[10] += arrows;
        int score1 = 0, score2=0;
        for(int i=0; i<11; i++){
            if(ryan[i] ==0 && apeach[i]==0) continue;
            if(ryan[i] > apeach[i]) score1 += (10-i);
            else score2 += (10-i);
        }
        
        int diff = score1 - score2;
        if(diff>0){
            if(diff > maxDiff){
                maxDiff = diff;
                answer = ryan;
            }
            if(diff == maxDiff){
                    for(int i=10; i>=0; i--){
                        if(ryan[i] > answer[i]){
                            answer = ryan; 
                            break;
                        } 
                        else if (ryan[i] < answer[i]) break;
                    }
                }
        }
        
        if (arrows>0) ryan[10] -= arrows;
        return;
    }
    
    
    // 해당 점수 획득
    if(arrows > apeach[idx]){
        ryan[idx] = apeach[idx]+1;
        dfs(idx+1, arrows-(apeach[idx]+1), ryan, apeach);
        ryan[idx] = 0;
    }
    
    // 해당 점수 포기
    dfs(idx+1, arrows, ryan, apeach);
    
}
vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11,0);
    dfs(0,n,ryan,info);
    if(answer.empty()) return {-1};
    return answer;
}
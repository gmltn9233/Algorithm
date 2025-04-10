#include <bits/stdc++.h>

using namespace std;
int N,ret;
int arr[6];


void check(vector<vector<int>> q, vector<int> ans){
    for(int i=0; i<q.size(); i++){
        int cnt = 0;
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(arr[k] == q[i][j]){
                    ++cnt;
                }
            }
        }
        if(cnt != ans[i]){
            return;
        }
    }
    ++ret;
}

void combi(int depth, int next,vector<vector<int>> q, vector<int> ans){
    if(depth == 5){
        check(q,ans);
        return;
    }
    for(int i=next; i<=N; i++){
        arr[depth] = i;
        combi(depth+1, i+1,q,ans);
    }
}


int solution(int n, vector<vector<int>> q, vector<int> ans) {
    N = n;
    combi(0,1,q,ans);
    return ret;
}




    
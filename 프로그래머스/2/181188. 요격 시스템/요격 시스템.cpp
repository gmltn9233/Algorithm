#include<bits/stdc++.h>
int ret;
using namespace std;

bool cmp(vector<int>a, vector<int>b){
    return a[1]<b[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),cmp);
    int end = targets[0][1];
    for(vector<int> target : targets){
        int start = target[0];
        if(end<=start){
            ++ret;
            end = target[1];
        }
    }
    ++ret;
    return ret;
}
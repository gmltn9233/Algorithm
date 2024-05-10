#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
vector<int> changeStartIdx(vector<int> weak, int start, int n){
    if(start == 0) return weak;
    vector<int> ret;
    for(int i=start; i<weak.size(); i++) ret.push_back(weak[i]);
    for(int i=0; i<start; i++) ret.push_back(weak[i]+n);
    return ret;
}

int solution(int n, vector<int> weak, vector<int> dist) {   
    int ret = INF;
    do{
        for(int i=0; i< weak.size(); i++){
            int idx = 0,flag=0;
            vector<int> weakList = changeStartIdx(weak,i,n);
            int curr = weakList[0]+dist[0];
            for(int j=1; j<weakList.size(); j++){
                if(weakList[j] > curr){
                    if(idx + 1 == dist.size()){
                        flag = 1; break;
                    }
                    curr = weakList[j] +dist[++idx];
                }
            }
            if(!flag) ret = min(ret,idx+1);
        }
    }while(next_permutation(dist.begin(),dist.end()));
    return (ret == INF ? -1 : ret);
}
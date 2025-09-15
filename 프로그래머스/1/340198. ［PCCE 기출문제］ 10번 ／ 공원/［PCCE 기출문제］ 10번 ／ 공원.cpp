#include <bits/stdc++.h>
using namespace std;
int mp[51][51],ret=1;
int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 1;
    int n = park.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<park[i].size(); j++){
            if(park[i][j].length()==2){
                mp[i][j]=1;
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<park[i].size(); j++){
            if(mp[i][j]==0) continue;
            if(park[i-1][j-1]==park[i][j-1] && park[i-1][j-1]==park[i-1][j]){
                mp[i][j] = min(mp[i-1][j-1],min(mp[i][j-1],mp[i-1][j]))+1;
                ret = max(mp[i][j],ret);
            }
        }
    }
    
    // cout<<"-----------------\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<mp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // cout<<ret<<"\n";
    
    sort(mats.begin(),mats.end());
    reverse(mats.begin(),mats.end());
    bool flag = false;
    for(auto mat : mats){
        if(mat<=ret){
            answer = mat;
            flag = true;
            break;
        }
    }
    if(!flag) answer = -1;
    return answer;
}
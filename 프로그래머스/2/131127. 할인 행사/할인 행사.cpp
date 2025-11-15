#include <bits/stdc++.h>

using namespace std;
map<string,int> mp;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0; i<want.size(); i++){
        mp[want[i]]=number[i];
    }
    

    for(int i=0; i<discount.size(); i++){
        //cout<<"idx:"<<i<<"\n";
        map<string,int> mpp = mp;
        for(int j=i; j<(int)min(i+10,(int)discount.size()); j++){
            mpp[discount[j]]--;
        }
        bool flag = true;
        for(auto it : mpp){
            //cout<<it.first<<","<<it.second<<"\n";
            if(it.second>0){
                flag = false;
                break;
            }
        }
        if(flag) ++answer;
    }
    return answer;
}
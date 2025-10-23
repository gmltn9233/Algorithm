#include <bits/stdc++.h>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> v;
    vector<double> preSum;
    preSum.push_back(0);
    v.push_back(k);
    int num = k;
    double prev_sum = 0;
    int prev = k;
    while(true){
        if(num%2==0) num/=2;
        else num=num*3+1;
        v.push_back(num);
        preSum.push_back(prev_sum + (prev+num)/(double)2);
        prev_sum = prev_sum+ (prev+num)/(double)2;
        prev= num;
        if(num==1) break;
    }
    int n = v.size()-1;
    
    for(auto range : ranges){
        int s = range[0];
        int e = range[1]*-1;
        //cout<<s<<","<<e<<"\n";
        //cout<<"넓이: "<<preSum[n-e]-preSum[s]<<"\n";
        if((n-e)<s) answer.push_back((double)-1);
        else answer.push_back(preSum[n-e]-preSum[s]);
    }
    
    
    
    return answer;
}
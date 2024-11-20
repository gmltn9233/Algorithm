#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> command : commands){
        vector<int> v;
        int I= command[0]-1;
        int J= command[1]-1;
        int K= command[2]-1;
        for(int i= I; i<=J; i++){
            v.push_back(array[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<< " ";
        }
        cout<<"\n";
        answer.push_back(v[K]);
    }
    return answer;
}
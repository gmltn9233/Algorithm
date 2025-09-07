#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
int fromCount[1000001];
int toCount[1000001];
int nodeCnt[1000001];
int edgeCnt[1000001];
set<int> numSet;
int nodeNum,dCnt,sCnt,eCnt;
int find(int idx){
    if(parent[idx] == idx) return idx;
    return find(parent[idx]);
}
void merge(int a, int b){
    int A = find(a);
    int B = find(b);
    if(A==B) return;
    nodeCnt[A] += nodeCnt[B];
    nodeCnt[B] = 0;
    edgeCnt[A] += edgeCnt[B]+1;
    edgeCnt[B] = 0;
    parent[B] = A;
}
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for(auto edge : edges){
        int from = edge[0];
        int to = edge[1];
        fromCount[from]++;
        toCount[to]++;
        numSet.insert(from);
        numSet.insert(to);
    }
    
    vector<pair<int,int>> num;
    for(int i=1; i<= numSet.size(); i++){
        if(toCount[i]==0){
            num.push_back({fromCount[i],i});
        }
    }
    
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    
    nodeNum = num[0].second;
    
    // 초기화
    for(auto it : numSet){
        parent[it] = it;
    }
    
    fill(&nodeCnt[0],&nodeCnt[0]+1000001, 1);

    for(auto edge : edges){
        
        int from = edge[0];
        int to = edge[1];
        
        if(from == nodeNum) continue;
        
        //cout<<from<<" to "<<to<<"\n";
        
        int A = find(from);
        int B = find(to);
        
        if(A==B){
            ++edgeCnt[A];
            // cout<<"A==B\n";
            // cout<<"AnodeSize: "<<nodeCnt[A]<<", AedgeCnt: "<<edgeCnt[A]<<"\n";
        }else{
            // cout<<"AnodeSize: "<<nodeCnt[A]<<", AedgeCnt: "<<edgeCnt[A]<<"\n";
            // cout<<"BnodeSize: "<<nodeCnt[B]<<", BedgeCnt: "<<edgeCnt[B]<<"\n";
            merge(A,B);
            // cout<<"merge\n";
            // cout<<"nodeSize: "<<nodeCnt[A]<<", edgeCnt: "<<edgeCnt[A]<<"\n";
        }
    }
    for(auto it : numSet){
        if(it == nodeNum) continue;
        if(nodeCnt[it]){
            if(nodeCnt[it]==edgeCnt[it]) ++dCnt;
            if(nodeCnt[it]==edgeCnt[it]+1) ++sCnt;
            if(nodeCnt[it]==edgeCnt[it]-1) ++eCnt;
        }
    }
    
    // for(auto it : numSet){
    //     cout<<it<<"nodeSize: "<<nodeCnt[it]<<", edgeCnt: "<<edgeCnt[it]<<"\n";
    // }
    answer.push_back(nodeNum);
    answer.push_back(dCnt);
    answer.push_back(sCnt);
    answer.push_back(eCnt);
    return answer;
}
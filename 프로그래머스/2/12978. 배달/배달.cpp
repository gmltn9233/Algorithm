#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
set<pair<int,int>> routes[52];
int dist[52][52];
void dijkstra(int start){
    dist[start][start] = 0;
    pq.push({0,start});
    
    while(pq.size()){
        int from = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        if(dist[start][from] < weight) continue;
        for(auto it : routes[from]){
            int to = it.first;
            int now_weight = it.second;
            if(dist[start][to] > dist[start][from] + now_weight){
                dist[start][to] = dist[start][from] + now_weight;
                pq.push({dist[start][to],to});
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(&dist[0][0], &dist[0][0]+52*52, INF);
    for(auto it : road){
        routes[it[0]].insert({it[1],it[2]});
        routes[it[1]].insert({it[0],it[2]});
    }
    
    dijkstra(1);
    
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    for(int i=1; i<=N; i++){
        if(dist[1][i] <= K) ++answer;
    }
    
    
    return answer;
}
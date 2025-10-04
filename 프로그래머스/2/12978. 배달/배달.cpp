#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

// 그래프: route[a] = { {b, w}, ... }
set<pair<int,int>> route[52];
int dist[52][52];

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int start){
    dist[start][start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        auto [cost, from] = pq.top();
        pq.pop();

        if(cost > dist[start][from]) continue;

        for(auto it : route[from]){
            int to = it.first;
            int weight = it.second;

            if(dist[start][to] > dist[start][from] + weight){
                dist[start][to] = dist[start][from] + weight;
                pq.push({dist[start][to], to});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    fill(&dist[0][0], &dist[0][0] + 52*52, INF);

    for(auto &it : road){
        int a = it[0];
        int b = it[1];
        int w = it[2];
        route[a].insert({b, w});
        route[b].insert({a, w});
    }

    dijkstra(1);

    for(int i=1; i<=N; i++){
        if(dist[1][i] <= K) answer++;
    }

    return answer;
}
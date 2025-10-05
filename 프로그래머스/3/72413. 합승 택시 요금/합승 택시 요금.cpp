#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int price[202][202];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    fill(&price[0][0], &price[0][0]+202*202, INF);
    for(int i=1; i<=n; i++){
        price[i][i]=0;
    }
    for(auto it : fares){
        price[it[0]][it[1]]=it[2];
        price[it[1]][it[0]]=it[2];
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(price[i][j] > price[i][k] + price[k][j]){
                    price[i][j] = price[i][k] + price[k][j];
                }
            }
        }
    }
    
    int answer = INF;
    
    for(int i=1; i<=n; i++){
        if(price[s][i]==INF || price[i][a]==INF || price[i][b]==INF) continue;
        answer = min(answer,price[s][i]+price[i][a]+price[i][b]);
    }
    answer = min(answer, price[s][a]+price[s][b]);
    return answer;
}
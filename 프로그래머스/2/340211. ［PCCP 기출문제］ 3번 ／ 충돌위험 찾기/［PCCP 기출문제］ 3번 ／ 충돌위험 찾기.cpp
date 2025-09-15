#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int mp[101][101];
pair<int,int> robot[101];
vector<int> robot_move[101];
vector<pair<int,int>> robot_route[101];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    memset(mp,0,sizeof(mp));
    
    // 초기 로봇 위치 + 경로 설정
    for(int i=0; i<routes.size(); i++){
        int prev = routes[i][0];
        robot[i] = {points[prev-1][0], points[prev-1][1]};
        
        for(int j=1; j<routes[i].size(); j++){
            int next = routes[i][j];
            int route_y = points[next-1][0]-points[prev-1][0];
            int route_x = points[next-1][1]-points[prev-1][1];
            robot_route[i].push_back({route_y,route_x});
            prev = next;
        }
    }
    
    // 이동 방향 기록 (세로 먼저, 가로 나중)
    for(int i=0; i<routes.size(); i++){
        for(auto it : robot_route[i]){
            int move_y = it.first;
            int move_x = it.second;
            for(int j=0; j<abs(move_y); j++){
                int dir = move_y < 0 ? 0 : 1; // 위 or 아래
                robot_move[i].push_back(dir);
            }
            for(int j=0; j<abs(move_x); j++){
                int dir = move_x < 0 ? 2 : 3; // 왼쪽 or 오른쪽
                robot_move[i].push_back(dir);
            }
        }
    }
    
    int max_move = 0;
    for(auto &it : robot_move){
        max_move = max((int)it.size(), max_move);
    }
    
    // 시뮬레이션
    for(int t=0; t<=max_move; t++){
        memset(mp,0,sizeof(mp));
        
        for(int j=0; j<routes.size(); j++){
            if(t > robot_move[j].size()){
                continue; // 로봇이 이미 운송 완료 -> 카운트 안 함
            }
            if(t > 0){ // t=0은 출발 좌표 그대로
                int dir = robot_move[j][t-1];
                robot[j].first  += dy[dir];
                robot[j].second += dx[dir];
            }
            mp[robot[j].first][robot[j].second]++;
        }
        
        // 좌표마다 위험 상황 카운트
        for(int y=0; y<=100; y++){
            for(int x=0; x<=100; x++){
                if(mp[y][x] >= 2) answer++;
            }
        }
    }
    
    return answer;
}
#include <bits/stdc++.h>

using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int solution(vector<vector<string>> board, int h, int w) {
    int n = board.size();
    int m = board[0].size();
    int answer = 0;
    for(int i=0; i<4; i++){
        int ny = h+dy[i];
        int nx = w+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
        if(board[ny][nx] == board[h][w]) ++answer;
    }
    return answer;
}
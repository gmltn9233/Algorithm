#include <string>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

bool BFS(int Y, int X, vector<string> place){
    int visited[5][5]={0};
    queue<pair<int,int>> q;
    visited[Y][X]=1;
    q.push(make_pair(Y,X));
    
    while(!q.empty()){
        int y= q.front().first;
        int x= q.front().second;
        q.pop();
        if(visited[y][x]>=3){
            break;
        }
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0||ny>=5||nx<0||nx>=5||visited[ny][nx]!=0||place[ny][nx]=='X') continue;
            if(place[ny][nx]=='P'){
               return false;
            }
            visited[ny][nx]= visited[y][x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    return true;
}


int isOk(vector<string> place){
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(place[i][j]=='P'){
                if(!BFS(i,j,place)){
                    return 0;
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0 ; i<5; i++){
        answer.push_back(isOk(places[i]));
    }
    return answer;
}
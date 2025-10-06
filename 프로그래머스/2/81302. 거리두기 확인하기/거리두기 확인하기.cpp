#include <bits/stdc++.h>

using namespace std;
int visited[6][6];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int k=0; k<places.size(); k++){
        //cout<<k+1<<"\n";
        bool flag = false;
    for(int i=0; i<5; i++){
        if(flag) break;
        for(int j=0; j<5; j++){
            if(flag) break;
            if(places[k][i][j]=='P'){
                //cout<<i<<","<<j<<"탐색 시작\n";
                queue<pair<int,int>> q;
                fill(&visited[0][0], &visited[0][0]+6*6, 0);
                visited[i][j]=1;
                q.push({i,j});
                while(q.size() && !flag){
                    int y = q.front().first;
                    int x = q.front().second;
                    if(visited[y][x] >=3) break;
                    q.pop();
                    for(int dir=0; dir<4; dir++){
                        int ny = y+dy[dir];
                        int nx = x+dx[dir];
                        
                        if(ny<0 || ny>=5|| nx<0 ||nx>=5) continue;
                        if(places[k][ny][nx]=='X') continue;
                        if(visited[ny][nx]) continue;
                        if(places[k][ny][nx]=='P'){
                            flag = true;
                            continue;
                        }
                        //cout<<ny<<","<<nx<<"\n";
                        visited[ny][nx] = visited[y][x]+1;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
        if(flag){
            answer.push_back(0);
            //cout<<"실패\n";
        } 
        else{
            answer.push_back(1);
            //cout<<"성공\n";
        } 
    }
    return answer;
}
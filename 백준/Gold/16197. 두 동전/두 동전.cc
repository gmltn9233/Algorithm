/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,m;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
char board[21][21];
int visited[21][21][21][21];
int ay=-1,ax=-1,by=-1,bx=-1;
bool outCheck(int ay, int ax, int by, int bx){
    if((ay < 0 || ay >=n || ax < 0 || ax >=m) && (by < 0 || by >=n || bx < 0 || bx >=m)) return false;
    if(ay < 0 || ay >=n || ax < 0 || ax >=m) return true;
    if(by < 0 || by >=n || bx < 0 || bx >=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            board[i][j] = s[j];
            if(board[i][j]=='o'){
                if(ay==-1 && ax==-1){
                    ay = i;
                    ax = j;
                }
                else{
                    by = i;
                    bx = j;
                }
            }
        }
    }
    
    int cnt = 0;
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{ay,ax},{by,bx}});
    while(q.size()){
        int ay = q.front().first.first;
        int ax = q.front().first.second;
        int by = q.front().second.first;
        int bx = q.front().second.second;
        q.pop();
        for(int i=0; i<4; i++){
            if (visited[ay][ax][by][bx] >= 10) continue;
            int nay = ay + dy[i];
            int nax = ax + dx[i];
            int nby = by + dy[i];
            int nbx = bx + dx[i];
            if(outCheck(nay,nax,nby,nbx)){
                cout<<visited[ay][ax][by][bx]+1;
                return 0;
            }
            
            if(nay < 0 || nay >=n || nax < 0 || nax >=m || nby < 0 || nby >=n || nbx < 0 || nbx >=m) continue;

            if(board[nay][nax]=='#' && board[nby][nbx]=='#') continue;
            if(board[nay][nax]=='#'){
                nay = ay;
                nax = ax;
            }
            if(board[nby][nbx]=='#'){
                nby = by;
                nbx = bx;
            }
            if(visited[nay][nax][nby][nbx]) continue;
            visited[nay][nax][nby][nbx] = visited[ay][ax][by][bx] +1;
            q.push({{nay,nax},{nby,nbx}});
        }
    }
    cout<<-1;
    return 0;
}

// 두 동전 중 하나만 보드에서 떨어트리기 위한 최소 버튼 수
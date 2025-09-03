#include <bits/stdc++.h>
using namespace std;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};
int n,m,k,d,ret;
int mp[22][22],visited[22][22];

struct gameDice{
    int north;
    int east;
    int south;
    int west;
    int up;
    int down;
};

gameDice dice({2,3,5,4,1,6});

void rollNorth(){
    int nn = dice.up;
    int ns = dice.down;
    int nu = dice.south;
    int nd = dice.north;
    
    dice.north = nn;
    dice.south = ns;
    dice.up = nu;
    dice.down = nd;
}
void rollEast(){
    int ne = dice.up;
    int nw = dice.down;
    int nu = dice.west;
    int nd = dice.east;
    
    dice.east = ne;
    dice.west = nw;
    dice.up = nu;
    dice.down = nd;
}
void rollSouth(){
    int nn = dice.down;
    int ns = dice.up;
    int nu = dice.north;
    int nd = dice.south;
    
    dice.north = nn;
    dice.south = ns;
    dice.up = nu;
    dice.down = nd;
}
void rollWest()
{
    int ne = dice.down;
    int nw = dice.up;
    int nu = dice.east;
    int nd = dice.west;
    
    dice.east = ne;
    dice.west = nw;
    dice.up = nu;
    dice.down = nd;
}

void rollDice(int d){
    if(d==3) rollNorth();
    if(d==0) rollEast();
    if(d==1) rollSouth();
    if(d==2) rollWest();
}

void go(int y, int x, int k){
    if(k==0) return;
    
    int ny = y+dy[d];
    int nx = x+dx[d];

    // 1. 칸 없다면 반대 방향
    if(ny<0 || ny>=n || nx<0 || nx>=m){
        d = (d+2)%4;
        ny = y+dy[d];
        nx = x+dx[d];
    }
    
    rollDice(d);
    
    // 2. 점수 획득
    fill(&visited[0][0],&visited[0][0]+(22*22),0);
    int cnt = 1;
    queue<pair<int,int>> q;
    q.push({ny,nx});
    visited[ny][nx]=1;
    while(q.size()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if(visited[ny][nx]) continue;
            if(mp[ny][nx]==mp[y][x]){
                ++cnt;
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
        }
    }
    
    int score = mp[ny][nx]*cnt;
    
    // 3. 이동방향 결정
    if(dice.down > mp[ny][nx]){
        d = (d+1)%4;
    }
    if(dice.down < mp[ny][nx]){
        d = (d+3)%4;
    }
    
    ret += score;
    
    go(ny,nx,k-1);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mp[i][j];
        }
    }
    
    int y=0,x=0;
    go(x,y,k);
    
    
    cout<<ret;

    return 0;
}
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n,k,num;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<vector<int>> fishbowls;
bool check(){
    int max_fishes = *max_element(fishbowls[0].begin(),fishbowls[0].end());
    int min_fishes = *min_element(fishbowls[0].begin(),fishbowls[0].end());
    return ((max_fishes - min_fishes) <= k);
}
void move_fish(){
    // 1. 물고기 수 조절
    map<pair<int,int>,int> mp;
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){
            if(fishbowls[y][x]==-1) continue;
            for(int i=0; i<4; i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                
                if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                if(fishbowls[ny][nx]==-1) continue;
                if(fishbowls[ny][nx] > fishbowls[y][x]){
                    int diff = (fishbowls[ny][nx] - fishbowls[y][x])/5;
                    if(diff){
                        mp[{ny,nx}] -= diff;
                        mp[{y,x}] += diff;
                    }
                }else{
                    int diff = (fishbowls[y][x]-fishbowls[ny][nx])/5;
                    if(diff){
                        mp[{ny,nx}] += diff;
                        mp[{y,x}] -= diff;
                    }
                }
            }
        }
    }
    
    for(auto it : mp){
        fishbowls[it.first.first][it.first.second] += (it.second/2);
    }
    // 2. 일렬로 놓기
    // vector<int> flat_fishbowls;
    // int idx = 0;
    // for(int x=0; x<n; x++){
    //     for(int y=0; y<n; y++){
    //         if(fishbowls[y][x]==-1) continue;
    //         flat_fishbowls.push_back(fishbowls[y][x]);
    //     }
    // }
    // fishbowls = vector<vector<int>>(n,vector<int>(n,-1));
    // fishbowls[0] = flat_fishbowls;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(fishbowls[i][j]==-1) continue;
            ++cnt;
        }
    }
  
    
    vector<vector<int>> new_fishbowls(n, vector<int>(n, -1));
    int idx = 0;
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
            if(fishbowls[y][x]==-1) continue;
            new_fishbowls[0][idx++] = fishbowls[y][x];
        }
    }
    
    fishbowls = new_fishbowls;
}
void move(){
    // 1. 어항에 물고기 넣기
    int min_fishes = *min_element(fishbowls[0].begin(), fishbowls[0].end());
    for(int i=0; i<n; i++){
        if(fishbowls[0][i] == min_fishes){
            fishbowls[0][i]++;
        }
    }
    // 2. 어항 돌리기
    int ly = 1;
    int lx = 1;
    int sx = 0;
    while(sx+ly+lx <=n){
        for(int y=0; y<ly; y++){
            for(int x=0; x<lx; x++){
                int ny = lx-x;
                int nx = sx + lx + y;
        
                fishbowls[ny][nx] = fishbowls[y][x+sx];
                fishbowls[y][x+sx]=-1;
                
            }
        }
        sx += lx;
        if(ly==lx) ly++;
        else lx++;
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<fishbowls[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    // 3. 물고기 옮기기
    move_fish();
    // 4. 공중부양 2 (2번 작업)
    int loop = 2;
    sx = 0;
    ly = 1;
    lx = n/2;
    while(loop--){
        for(int y=0; y<ly; y++){
            for(int x=0; x<lx; x++){
                int ny = 2*ly-y-1;
                int nx = 2*lx+sx-x-1;
                fishbowls[ny][nx] = fishbowls[y][sx+x];
                fishbowls[y][sx+x] = -1;
            }
        }
        sx += lx;
        lx /=2;
        ly *=2;
    }
    // 5. 물고기 옮기기
    move_fish();
}
int solve(){
    int cnt = 0;
    while(!check()){
        ++cnt;
        move();
    }
    return cnt;
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    cin>>n>>k;
    fishbowls = vector<vector<int>>(n,vector<int>(n,-1));
    for(int i=0; i<n; i++){
        cin>>fishbowls[0][i];
    }
    
    cout<<solve();
    
    return 0;
}
// ny->lx-x
// nx->sx + ly - y


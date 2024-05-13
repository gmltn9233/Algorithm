#include<bits/stdc++.h>
using namespace std;

void rotateKey(vector<vector<int>> &key){
    int m = key.size();
    vector<int> temp;
    for(int j=0; j<m; j++){
        for(int i=m-1; i>=0; i--){
            temp.push_back(key[i][j]);
        }
    }
    int idx = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            key[i][j]=temp[idx];
            idx++;
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m=key.size(),n=lock.size(),cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(lock[i][j]==0){
                ++cnt;
            }
        }
    }
    
    for(int k=0; k<4; k++){
        rotateKey(key);
        for(int i=-m+1; i<n; i++){
            for(int j=-m+1; j<n; j++){
                int check = 0;
                for(int y=0; y<m; y++){
                    for(int x=0; x<m; x++){
                        int ny = y+i;
                        int nx = x+j;
                        if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
                        if(key[y][x]==lock[ny][nx]){
                            break;
                        }
                        if(key[y][x]==1 && lock[ny][nx]==0){
                            ++check;
                        }
                    }
                }
                if(check==cnt){
                    return true;
                }
            }
        }
    }
    return false;
}

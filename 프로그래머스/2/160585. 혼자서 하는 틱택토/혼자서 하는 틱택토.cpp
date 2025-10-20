#include <bits/stdc++.h>

using namespace std;
map<char,int> mp;
int o,x;
int solution(vector<string> board) {
    int answer = 1;
    for(string ch : board){
        for(auto it : ch){
            mp[it]++;
        }
    }
    // 가로
    if(board[0][0]==board[0][1] && board[0][1]==board[0][2]){
        if(board[0][0]=='O') ++o;
        if(board[0][0]=='X') ++x;
    }
    if(board[1][0]==board[1][1] && board[1][1]==board[1][2]){
        if(board[1][0]=='O') ++o;
        if(board[1][0]=='X') ++x;
    }
    if(board[2][0]==board[2][1] && board[2][1]==board[2][2]){
        if(board[2][0]=='O') ++o;
        if(board[2][0]=='X') ++x;
    }
    // 세로
    if(board[0][0]==board[1][0] && board[1][0]==board[2][0]){
        if(board[0][0]=='O') ++o;
        if(board[0][0]=='X') ++x;
    }
    if(board[0][1]==board[1][1] && board[1][1]==board[2][1]){
        if(board[0][1]=='O') ++o;
        if(board[0][1]=='X') ++x;
    }
    if(board[0][2]==board[1][2] && board[1][2]==board[2][2]){
        if(board[2][2]=='O') ++o;
        if(board[2][2]=='X') ++x;
    }
    // 대각선
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]=='O') ++o;
        if(board[0][0]=='X') ++x;
    }
    
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][2]=='O') ++o;
        if(board[0][2]=='X') ++x;
    }
    // 1. 둘 다 승리 조건을 가지고 있음
    if(o && x) return 0;
    // 3. 'O' 가 승리했음에도 'X'의 개수보다 작거나 같음
    if(o == 1 && mp['O'] <= mp['X']) return 0;
    // 4. 'X' 가 승리했음에도 'O' 가 더 많음
    if(x == 1 && mp['O'] > mp['X']) return 0;
    // 5. 'O' 가 'X' 보다 2개 더 많음
    if(mp['O'] >= mp['X']+2) return 0;
    // 6. 'O' 가 'X' 보다 적음
    if(mp['O'] < mp['X']) return 0;
    
    
    return 1;
}
// 1. 'O'나 'X' 가 완성한 후에도 O가 하나 더 많음
// 2. 선공 'O' 가 완성한 후에도 'X'와 갯수가 같음
// 3. 'O' 가 'X' 보다 2개 더 많음
// 4. 'O' 가 'X' 보다 적음
// 5. 승리 조건이 1개 이상

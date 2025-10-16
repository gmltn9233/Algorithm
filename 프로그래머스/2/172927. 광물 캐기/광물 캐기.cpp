#include <bits/stdc++.h>

using namespace std;
int answer=987654321;
int n;
vector<string> Minerals;
void go(int diamond, int iron, int stone, int idx, int num){
    //cout<<"diamond: "<<diamond<<",iron: "<<iron<<",stone: "<<stone<<"idx: "<<idx<<", num:"<<num<<"\n";
    if((diamond==0 && iron==0 && stone==0 ) || idx == n){
        answer = min(answer,num);
        return;
    }
    int count = min(n-idx,5);
    // 다이아 곡괭이
    if(diamond > 0){
        //cout<<"diamond!\n";
        int now = count;
        go(diamond-1, iron, stone, idx+count, num+now);
    }
    // 철 곡괭이
    if(iron > 0){
        //cout<<"iron!\n";
        int now = 0;
        for(int i=0; i<count; i++){
            if(Minerals[idx+i]=="diamond"){
                now +=5;
            }
            else if(Minerals[idx+i] == "iron"){
                now +=1;
            }
            else{
                now +=1;
            }
        }
        go(diamond, iron-1, stone, idx+count, num+now);
    }
    // 돌 곡괭이
    if(stone > 0){
        //cout<<"stone!\n";
        int now = 0;
        for(int i=0; i<count; i++){
            if(Minerals[idx+i]=="diamond"){
                now +=25;
            }
            else if(Minerals[idx+i] == "iron"){
                now +=5;
            }
            else{
                now +=1;
            }
        }
        go(diamond, iron, stone-1, idx+count, num+now);
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    Minerals = minerals;
    n = minerals.size();
    go(picks[0],picks[1],picks[2],0,0);
    return answer;
}
// 최소한의 피로도
#include<bits/stdc++.h>

using namespace std;
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int prev=0;
    for(int station : stations){
        int a = (station - w -1) -prev;
        int b = (int)ceil((double)a/(double)(w*2+1));
        answer += b;
        prev = station + w;
    }
    answer += (int)ceil((double)(n-prev)/(double)(w*2+1));

    return answer;
}
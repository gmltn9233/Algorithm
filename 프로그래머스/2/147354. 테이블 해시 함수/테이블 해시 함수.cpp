#include <bits/stdc++.h>

using namespace std;
int Col;
bool cmp(vector<int> a, vector<int> b){
    if(a[Col-1] == b[Col-1]) return a[0] > b[0];
    return a[Col-1] < b[Col-1];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    Col = col;
    sort(data.begin(),data.end(),cmp);
    for(int i=row_begin; i<=row_end; i++){
        int sum = 0;
        for(auto it : data[i-1]){
            sum += (it%i);
        }
        answer = (answer^sum);
    }
    
    return answer;
}
#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    for(int i=0; i<number.size()-1; i++){
        if(number[i]<number[i+1]){
            number.erase(number.begin()+i);
            --k;
            i=-1;
        }
        if(k==0){
            break;
        }
    }
    
    if(k>0){
        for(int i=0; i<k; i++){
            number.erase(number.end()-1);
        }
    }
    string answer = number;
    
    return answer;
}

    
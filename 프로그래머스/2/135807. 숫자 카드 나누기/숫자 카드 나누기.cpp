#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    long long gcd_A = arrayA[0];
    long long gcd_B = arrayB[0];
    for(auto it : arrayA){
        gcd_A = gcd(gcd_A,it);
    }
    for(auto it : arrayB){
        gcd_B = gcd(gcd_B,it);
    }
    bool flagA=false, flagB=false;
    for(int i=0; i<arrayA.size(); i++){
        if(arrayB[i]%gcd_A==0){
            flagA=true;
        }
        if(arrayA[i]%gcd_B==0){
            flagB=true;
        }
    }
    //cout<<gcd_A<<","<<gcd_B<<"\n";
    //cout<<flagA<<","<<flagB<<"\n";
    if(flagA) gcd_A = 0;
    if(flagB) gcd_B = 0;
    
    
    return max(gcd_A,gcd_B);
}

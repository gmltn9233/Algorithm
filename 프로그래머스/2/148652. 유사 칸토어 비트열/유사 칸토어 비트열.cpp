#include <bits/stdc++.h>

using namespace std;
long long count_1[21];
long long num_len[21];
long long go(long long n, long long k){
    //cout<<"-------------\n";
    long long len = num_len[n-1];
   // cout<<len<<"\n";
    long long num = k/len;
    //cout<<num<<"\n";
    long long rem = k%len;
    //cout<<rem<<"\n";
    long long ret = 0;
    if(num <= 2) ret = count_1[n-1]*num;
    if(num > 2) ret = count_1[n-1]*(num-1);
    
    //cout<<"ret: "<<ret<<"\n";
    if(num == 2 || rem ==0) return ret;
    else return ret + go(n-1,rem);
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    count_1[0] = 1;
    num_len[0] = 1;
    for(int i=1; i<=n; i++){
        count_1[i] = count_1[i-1]*4;
        num_len[i] = num_len[i-1]*5;
    }
    return go(n,r)-go(n,l-1);
}

// 1 -> 11011 -> 11011 11011 00000 11011 11011
// 0 -> 00000

// 1-> 4 -> 16 -> .... 4^k
// 5의 배수 단위로 11011 이거나 00000
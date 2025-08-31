#include <bits/stdc++.h>
using namespace std;
int n,m;
long long num,mod = 1000000000;
vector<long long> A,B;
long long gcd(long long a, long long b){
    while(b!=0){
        long long r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num;
        A.push_back(num);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>num;
        B.push_back(num);
    }
    bool flag = false;
    long long ret =1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int num = gcd(A[i],B[j]);
            if(num > 1){
                A[i] /= num;
                B[j] /= num;
                if(ret*num >= mod){
                    flag = true;
                }
                ret = (ret*num)%mod;
            }
        }
    }
    if(flag){
        long long ret2 = ret;
        int cnt = 1;
        while(ret2>10){
            ret2/=10;
            ++cnt;
        }
        int zeroCnt = 9-cnt;
        for(int i=0; i<zeroCnt; i++){
            cout<<"0";
        }
        cout<<ret;
    }else{
        cout<<ret;
    }
    return 0;
}
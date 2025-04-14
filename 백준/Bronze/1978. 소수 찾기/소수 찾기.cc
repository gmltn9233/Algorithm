#include <bits/stdc++.h>
using namespace std;

int a[1001];
int n,ret;
int main()

{
    cin>>n;
    for(int i=2; i<=1000; i++){
        int cnt = 0;
        for(int j=i; j>=1; j--){
            if(i%j == 0) ++cnt;
            if(cnt>2) break;
        }
        if(cnt<=2) a[i] = 1;
    }
    
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        if(a[num]==1){
            ++ret;
        }
    }
    
    cout<<ret;
    return 0;
}
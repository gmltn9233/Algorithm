#include <bits/stdc++.h>

using namespace std;
int t;
int main()
{
    cin>>t;
    while(t--){
        int c;
        cin>>c;
        int q = c/25;
        int d = (c-(25*q))/10;
        int n = (c-(25*q)-(10*d))/5;
        int p = (c-(25*q)-(10*d)-(5*n));
        cout<<q<<" "<<d<<" "<<n<<" "<<p<<"\n";
    }
    return 0;
}
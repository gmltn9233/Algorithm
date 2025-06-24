/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int n;
map<int,int> mp;
int a[2500][2500];
void go(int sy, int sx, int ey, int ex){
    int temp = a[sy][sx];
    bool same = true;
    for(int i = sy; i<ey; i++){
        for(int j= sx; j<ex; j++){
            if(temp != a[i][j]){
                same = false;
                break;
            }
        }
    }
    if(same){
        mp[temp]++;
        return;
    }
    
    go(sy,sx,sy+(ey-sy)/3,sx+(ex-sx)/3);
    go(sy,sx+(ex-sx)/3,sy+(ey-sy)/3,sx+(ex-sx)/3*2);
    go(sy,sx+(ex-sx)/3*2,sy+(ey-sy)/3,ex);
    go(sy+(ey-sy)/3,sx,sy+(ey-sy)/3*2,sx+(ex-sx)/3);
    go(sy+(ey-sy)/3,sx+(ex-sx)/3,sy+(ey-sy)/3*2,sx+(ex-sx)/3*2);
    go(sy+(ey-sy)/3,sx+(ex-sx)/3*2,sy+(ey-sy)/3*2,ex);
    go(sy+(ey-sy)/3*2,sx,ey,sx+(ex-sx)/3);
    go(sy+(ey-sy)/3*2,sx+(ex-sx)/3,ey,sx+(ex-sx)/3*2);
    go(sy+(ey-sy)/3*2,sx+(ex-sx)/3*2,ey,ex);
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    go(0,0,n,n);
    cout<<mp[-1]<<"\n";
    cout<<mp[0]<<"\n";
    cout<<mp[1]<<"\n";
    
    return 0;
}
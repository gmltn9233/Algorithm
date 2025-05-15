/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[301][301];
void rotate(int y1, int x1, int y2, int x2){
    int temp = a[y1][x1];
    // 위쪽
    for(int i=x1+1; i<=x2; i++){
        a[y1][i-1] = a[y1][i]; 
    }
    // 오른쪽
    for(int i=y1+1; i<=y2; i++){
        a[i-1][x2] = a[i][x2];
    }
    // 아래쪽
    for(int i=x2; i>=x1+1; i--){
        a[y2][i] = a[y2][i-1]; 
    }
    // 왼쪽
    for(int i=y2; i>=y1+1; i--){
        a[i][x1] = a[i-1][x1];
    }
    a[y1+1][x1] = temp;
}
void rotateAll(){
    int y1=0, x1=0;
    int y2=n-1, x2=m-1;
    while(x1 <= x2 && y1 <= y2){
        rotate(y1,x1,y2,x2);
        y1++,x1++;
        y2--,x2--;
    }
}
int main()
{
    cin>>n>>m>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    while(r--){
        rotateAll();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
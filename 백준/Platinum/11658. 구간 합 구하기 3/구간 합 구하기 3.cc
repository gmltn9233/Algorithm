#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,w,a,b,c,d,C;
int arr[1030][1030], tree[1030][1030];
void update(int y,int x, int value){
	while(y<=n){
		int j=x;
		while(j<=n){
			tree[y][j] += value;
			j += (j & -j);
		}
		y += (y&-y);
	}
	return;
}
int sum(int y, int x){
	int num = 0;
	while(y>0){
		int j = x;
		while(j>0){
			num+= tree[y][j];
			j-=(j&-j);
		}
		y-=(y&-y);
	}
	return num;
}
int main() {
    cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>arr[i][j];
			update(i,j,arr[i][j]);
		}
	}
	while(m--){
		cin>>w;
		if(w==0){
			cin>>a>>b>>C;
			update(a,b,C-arr[a][b]);
			arr[a][b]=C;
		}
		else{
			cin>>a>>b>>c>>d;
			cout<<sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1)<<"\n";
		}
	}
	return 0;
}
 
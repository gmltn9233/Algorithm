#include<bits/stdc++.h>
using namespace std;
int n,m,h,a,b;
int flag[34][34];
int ret=987654321;
int ladder(int n){
	int j=n;
	for(int i=1; i<=h;i++){
		if(flag[i][j]) ++j;
		else if(flag[i][j-1]) --j;
	}
	return j;
}

bool goodLadder(){
	for(int i=1; i<=n; i++){
		if(ladder(i)!=i) return false;
	}
	return true;
}

void go(int here, int cnt){
	if(cnt>3 || cnt>= ret) return;
	if(goodLadder()){
		ret=min(ret,cnt); return;
	}
	for(int i=here; i<=h; i++){
		for(int j=1; j<n; j++){
			if(flag[i][j]||flag[i][j-1]||flag[i][j+1]) continue;
			flag[i][j]=1;
			go(i,cnt+1);
			flag[i][j]=0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	cin>>n>>m>>h;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		flag[a][b]=1;
	}
	go(1,0);
	cout<<((ret==987654321)?-1:ret)<<'\n';
	return 0;
}
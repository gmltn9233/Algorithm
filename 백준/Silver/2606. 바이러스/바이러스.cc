#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m,a,b,ret;
int arr[101][101];
bool visited[101];
void go(int idx){
	visited[idx]=true;
	for(int i=1; i<=n; i++){
		if(arr[idx][i]==1 && visited[i]==false){
			go(i);
		}
	}
	return;
}
int main() {
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		arr[a][b]=1;
		arr[b][a]=1;	
	}
	go(1);
	for(int i=1; i<=n; i++){
		if(visited[i]) ++ret;
	}
	cout<<ret-1;
	return 0;
}

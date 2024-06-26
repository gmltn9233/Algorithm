#include<bits/stdc++.h>
using namespace std;
int k;
vector<int> ret[12];
int visited[1030], a[1030];

void go(int s,int e, int level){
	if(s>e) return;
	if(s==e){
		ret[level].push_back(a[s]);
		return;
	}
	int mid= (s+e)/2;
	ret[level].push_back(a[mid]);
	go(s,mid-1,level+1);
	go(mid+1,e,level+1);
	return;
}

int main(){
	cin>> k;
	cin>>a[0];
	int _end=(int)pow(2,k)-1;
	for(int i=1; i<_end; i++){
		cin>>a[i];
	}
	go(0,_end,1);
	for(int i=1; i<=k;i++){
		for(int j: ret[i]){
			cout<<j<<" ";
		}
		cout<<'\n';
	}
}
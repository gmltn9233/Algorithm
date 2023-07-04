#include <bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=100004;
vector<int>v;
queue<int>q;
int visited[max_n],prevv[max_n];
int here,ret;
int main () {
	cin>>n>>k;
	visited[n]=1;
	q.push(n);
	while(q.size()){
		here=q.front();
		q.pop();
		if(here==k){
			ret=visited[k];
			break;
		}
		for(int next: {here+1,here-1,here*2}){
			if(next>=max_n||next<0||visited[next]) continue;
			visited[next]=visited[here]+1;
			prevv[next]=here;
			q.push(next);
		}
	}
	for(int i=k; i!=n; i=prevv[i]){
		v.push_back(i);
	}
	v.push_back(n);
	cout<<ret-1<<'\n';
	reverse(v.begin(),v.end());
	for(int i:v) cout<<i<<' ';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a,b;
int visited[2][500004];
int ok,turn=1;
queue<int> q;
int main () {
	cin>>a>>b;
	if(a==b){
		cout<<0<<'\n';
		return 0;
	}
	visited[0][a]=1;
	q.push(a);
	while(q.size()){
		b+=turn;
		if(b>500000) break;
		if(visited[turn%2][b]){
			ok=true;
			break;
		}
		int qSize=q.size();
		for(int i=0; i<qSize; i++){
			int x=q.front();
			q.pop();
			for(int nx:{x+1,x-1,x*2}){
				if(nx<0||nx>500000||visited[turn%2][nx]) continue;
				visited[(turn)%2][nx]=visited[(turn+1)%2][x]+1;
				if(nx==b){
					ok=1;
					break;
				}
				q.push(nx);
			}
			if(ok) break;
		}
		if(ok) break;
		turn++;
	}
	if(ok) cout<<turn<<'\n';
	else cout<<-1<<'\n';
	return 0;
}


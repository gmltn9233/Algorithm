#include<bits/stdc++.h>
using namespace std;
int k;
char a[10];
int visited[10];
vector<string> ret;

bool ok(char now, char next, char c){
	if(c=='<'&&now<next){
		return true;
	}
	else if (c=='>'&&now>next){
		return true;
	}
	return false;
}

void go(int index, string num){
	if(index==k+1){
		ret.push_back(num); return;
	}
	for(int i=0; i<=9; i++){
		if(visited[i]) continue;
		if(index==0||ok(num[index-1],i+'0',a[index-1])){
			visited[i]=1;
			go(index+1,num+to_string(i));
			visited[i]=0;
		}
	}
	return;
}

int main(){
	cin>>k;
	for(int i=0; i<k; i++){
		cin>>a[i];
	}
	go(0,"");
	sort(ret.begin(),ret.end());
	cout<<ret[ret.size()-1] << '\n'<<ret[0];
	
}
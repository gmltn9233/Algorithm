#include<bits/stdc++.h> 
using namespace std;
int n,m,c;
int a[21];
int dp[21][1<<14][21];
int go(int bag, int jewl, int capacity){
	if(bag == m) return 0;
	int &ret = dp[bag][jewl][capacity];
	if(ret) return ret;
	
	// 담지 않을때
	ret = max(ret, go(bag+1,jewl,c));
	// 담을때 
	for(int i=0; i<n; i++){
		bool isInBag = (1<<i) & jewl;
		bool canInBag = (capacity - a[i]) >= 0;
		if(!isInBag && canInBag) ret = max(ret,go(bag,jewl | (1<<i), capacity-a[i])+1);
	}
	return ret;
}
int main(){
	cin>>n>>m>>c;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<go(0,0,c);
	
}
       
// 1<=n(보석)<=13
// 1<=m(가방)<=10
// 1<=c(가방 무게)<=20
// 1<=(보석 무게)<=20 
// 훔칠 수 있는 최대 개수 

// 1. 처음 든 생각 : 보석 가벼운순으로 sort 하고 계속 담으면 되지않나?
// 1 2 3 4 5 -> (1,2),(3) x (1,4), (1,5) 정답 
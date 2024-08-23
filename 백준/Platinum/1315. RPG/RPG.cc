#include<bits/stdc++.h> 
using namespace std;
int n,STR[51],INT[51],PNT[51];
int dp[1001][1001];
bool visited[51];
int go(int str, int _int){
	int &ret = dp[str][_int];
	if(ret != -1) return ret;
	ret = 0;
	
	int pnt = 0;
	vector<int> v;
	for(int i=0; i<n; i++){
		if(str>=STR[i] || _int >= INT[i]){
			++ret;
			if(!visited[i]){
				v.push_back(i);
				visited[i] = true;
				pnt += PNT[i];
			}
			
		}
	}
	for(int i=0; i<= pnt; i++){
		int next_str = min(1000,str + i);
		int next_int = min(1000,_int + (pnt - i));
		ret = max(ret, go(next_str,next_int));
	}
	
	for(int i : v){
		visited[i]=false;
	}
	
	return ret;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>STR[i]>>INT[i]>>PNT[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<go(1,1);
 	return 0;
} 

// 힘(STR) or 지력(INT)
// N개의 퀘스트 
// i 번째 퀘스트:
// 캐릭터의 힘 >= STR or 지력 >= INT
// 퀘스트 깨면 포인트 PNT[i] ++;
// 단 한번만 깰 수 있다.
// 순서는 상관 없다.
// 보상 스탯도 마음대로이다.
// 퀘스트 개수의 최댓값? 
// N<=50

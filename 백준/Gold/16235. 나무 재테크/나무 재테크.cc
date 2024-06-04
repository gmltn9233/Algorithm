#include<bits/stdc++.h> 
using namespace std;
int n,m,k,y,x,z; 
vector<int> a[11][11];
int food[11][11], ground[11][11];
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
void springAndSummer(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j].size()==0) continue;
			sort(a[i][j].begin(),a[i][j].end());
			vector<int> temp;
			vector<int> dieTree;
			for(int tree : a[i][j]){
				if(tree <= ground[i][j]){
					temp.push_back(tree+1);
					ground[i][j]-= tree;
				}
				else{
					dieTree.push_back(tree);
				}
			}
			a[i][j]=temp;
			for(int tree : dieTree){
				ground[i][j] += tree/2;
			}
		}
	}
}
void growTree(int y,int x){
	for(int i=0; i<8; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
		a[ny][nx].push_back(1);
	}
}
void autumn(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(a[i][j].size()==0) continue;
			for(int tree : a[i][j]){
				if(tree % 5 ==0){
					growTree(i,j);
				}
			}
		}
	}
}
void winter(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ground[i][j] += food[i][j];
		}
	}
}
int checkTree(){
	int num = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			num += a[i][j].size();
		}
	}
	return num;
}
void printGround(){
	cout<<"Ground! \n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<ground[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main() {
	cin>>n>>m>>k;
	
	//초기 양분 상태 
	fill(&ground[0][0],&ground[0][0] + (11*11), 5);	
	
	// 겨울에 주어지는 양분 입력 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>food[i][j];
		}
	}
	
	// 심은 나무 입력 
	for(int i=0; i<m; i++){
		cin>>y>>x>>z;
		a[y-1][x-1].push_back(z);
	}
	
	
	//년도 갱신
	for(int i=0; i<k; i++){
		//printGround();
		//봄,여름 
		springAndSummer();
		//가을
		autumn();
		//겨울 
		winter();
	}
	cout<<checkTree();
	return 0;
}

// N*N 땅 (초기양분 5)
// 나무 M개
// 봄 : 나무가 자신의 나이만큼 양분--  -> 나이 1증가
//      어린 나무 우선, 양분 못먹으면 사망
// 여름 : 죽은 나무 양분화 -> 해당칸 양분 += (죽은나무 나이 / 2)  
// 가을 : 나무 번식, 자기 주위 8칸 나이 1인 나무 생성
// 겨울 : 양분 추가 (입력으로 주어짐) 
// K년이 지난 후 살아있는 나무 갯수? 
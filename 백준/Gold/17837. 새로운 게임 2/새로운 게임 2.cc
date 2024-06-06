#include<bits/stdc++.h> 
using namespace std;
int n,k,x,y,d,cnt=1; 
int mp[13][13];
stack<int> horseMap[13][13];
vector<int> horse[11];
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0}; 

// 방향 반대로 바꾸기 
int changeDir(int num){
	if(num == 0) return 1;
	if(num == 1) return 0;
	if(num == 2) return 3;
	if(num == 3) return 2;
}
// 말 움직이기 
void move(int y, int x, int dir, int idx,int turn){
	// 다음 지점 
	int ny = y+dy[dir];
	int nx = x+dx[dir];
	// 다음 지점 검토 
	if(mp[ny][nx]==2 || ny<0 || ny>=n || nx<0 ||nx>=n){
		// 다음 지점이 범위 밖이거나
		// 파란색 바닥일 경우 방향을 바꿈 
		horse[idx][2]=changeDir(horse[idx][2]);
		dir = horse[idx][2];
		ny = y+dy[dir];
	    nx = x+dx[dir];
		// 바꿔도 같다면 return(이동X) 
		if(mp[ny][nx]==2 || ny<0 || ny>=n || nx<0 ||nx>=n) return;
	}
	
	// 하양
	if(mp[ny][nx]==0){
		vector<int> v;
		// 자기 위에 있는것 먼저 벡터에 삽입 
		while(horseMap[y][x].top()!=idx){
			v.push_back(horseMap[y][x].top());
			// 말의 이동: 말의 좌표를 갱신해줌 
			horse[horseMap[y][x].top()][0]=ny;
			horse[horseMap[y][x].top()][1]=nx;
			// pop
			horseMap[y][x].pop();
		}
		// 현재 index의 말 같은 로직 실행 
		v.push_back(horseMap[y][x].top());
		horse[idx][0]=ny;
		horse[idx][1]=nx;
		horseMap[y][x].pop();
		// 벡터 순서 뒤집기 
		for(int i = v.size()-1; i>=0; i--){
			// horseMap에 삽입 
			horseMap[ny][nx].push(v[i]);
		}
	}
	
	// 빨강 
	if(mp[ny][nx]==1){
		// 자기 위에 있는것 먼저 벡터에 삽입
		while(horseMap[y][x].top()!=idx){
			horseMap[ny][nx].push(horseMap[y][x].top());
			// 말의 이동: 말의 좌표를 갱신해줌 
			horse[horseMap[y][x].top()][0]=ny;
			horse[horseMap[y][x].top()][1]=nx;
			// pop 
			horseMap[y][x].pop();
		}
		// 현재 index의 말 같은 로직 실행 
		horseMap[ny][nx].push(horseMap[y][x].top());
		horse[idx][0]=ny;
		horse[idx][1]=nx;
		horseMap[y][x].pop();
	}
	
	// 움직인 지점의 말이 4개이상 쌓여있다면 종료 
	if(horseMap[ny][nx].size()>=4){
		cout<<turn;
		exit(0);
	}
}
int main() {
	cin>>n>>k;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>mp[i][j];
			// 0: 흰, 1: 빨, 2: 파 
		}
	}
	// 행, 열, 이동방향 (오,왼,위,아래) 
	for(int i=1; i<=k; i++){
		cin>>y>>x>>d;
		horse[i].push_back(y-1);
		horse[i].push_back(x-1);
		horse[i].push_back(d-1);
		horseMap[y-1][x-1].push(i); 
	}
	while(cnt<1000){
		// 현재 턴이 1,000 이상이라면 종료 
		for(int i=1; i<=k; i++){
			move(horse[i][0],horse[i][1],horse[i][2],i,cnt);
		}
		cnt++;
	} 
	 
	cout<<-1;
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;
int n,k,x,y,d; 
int mp[13][13];
stack<int> horseMap[13][13];
vector<int> horse[11];

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0}; 
int changeDir(int num){
	if(num == 0) return 1;
	if(num == 1) return 0;
	if(num == 2) return 3;
	if(num == 3) return 2;
}
void move(int y, int x, int dir, int idx,int turn){
	//cout<<"idx: "<<idx<<"\n";
	// 다음 지점 
	int ny = y+dy[dir];
	int nx = x+dx[dir];
	// 다음 지점 검토 
	if(mp[ny][nx]==2 || ny<0 || ny>=n || nx<0 ||nx>=n){
		horse[idx][2]=changeDir(horse[idx][2]);
		dir = horse[idx][2];
		ny = y+dy[dir];
	    nx = x+dx[dir];
		// 바꿔도 같다면 return 
		if(mp[ny][nx]==2 || ny<0 || ny>=n || nx<0 ||nx>=n) return;
	}
	//하양
	if(mp[ny][nx]==0){
		vector<int> v;
		//cout<<"ny: "<<ny<<" nx: "<<nx<<"\n";
		while(horseMap[y][x].top()!=idx){
			v.push_back(horseMap[y][x].top());
			horse[horseMap[y][x].top()][0]=ny;
			horse[horseMap[y][x].top()][1]=nx;
			horseMap[y][x].pop();
		}
		v.push_back(horseMap[y][x].top());
		horse[idx][0]=ny;
		horse[idx][1]=nx;
		horseMap[y][x].pop();
		reverse(v.begin(),v.end());
		for(int num : v){
			horseMap[ny][nx].push(num);
			//cout<<num<<"\n";
		}
	}
	//빨강 
	if(mp[ny][nx]==1){
		while(horseMap[y][x].top()!=idx){
			horseMap[ny][nx].push(horseMap[y][x].top());
			horse[horseMap[y][x].top()][0]=ny;
			horse[horseMap[y][x].top()][1]=nx;
			horseMap[y][x].pop();
		}
		horseMap[ny][nx].push(horseMap[y][x].top());
		horse[idx][0]=ny;
		horse[idx][1]=nx;
		horseMap[y][x].pop();
	}
	
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
	int cnt = 1;
	while(cnt<=1000){
		//cout<<"----------"<<cnt<<"----------\n";
		for(int i=1; i<=k; i++){
			move(horse[i][0],horse[i][1],horse[i][2],i,cnt);
		}
		//for(int i=1; i<=k; i++){
			//cout<<i<<" : "<<horse[i][0]+1<<","<<horse[i][1]+1<<","<<horse[i][2]+1<<"\n";
		//}
		cnt++;
	} 
	 
	cout<<-1;
	return 0;
}
// 13:30
// N*N 체스판 
// 말의 개수 K (흰,빨,파,  번호 순서대로 이동)
// 말이 겹쳐져 있으면 같이 이동 
// 말이 4개 이상 쌓이는 순간 게임 종료 

// 흰색 -> 이동
// 빨간색 -> 순서 바꾼 뒤집고 이동
// 파란색 -> 이동방향 반대, 1칸 이동 
//        -> 바꿨는데 파란색이면 이동 x
// 체스판을 벗어나는 경우는 파란색과 같음



#include<bits/stdc++.h>
using namespace std; 
int a[51][51];
int n,m,t,x,d,k,ret;
vector<pair<int,int>> vv;
bool flag = false;
void printCircle(){
	cout<<"-----------------\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void clearCircle(int i,int j){
	int num = a[i][j]; 
	if(num!= -1){
		if(j==0){
			if(a[i][m-1]==num){
				flag = true;
				vv.push_back({i,m-1});
				vv.push_back({i,j});
			}
			if(a[i][j+1]==num){
				flag = true;
				vv.push_back({i,j+1});
				vv.push_back({i,j});
			}
		}
		else{
			if(a[i][j-1] == num){
				flag = true;
				vv.push_back({i,j-1});
				vv.push_back({i,j});
			}
			if(a[i][j+1] == num){
				flag = true;
				vv.push_back({i,j+1});
				vv.push_back({i,j});
			}
		}
		if(i==n-1){
			if(a[i-1][j] == num){
				flag = true;
				vv.push_back({i-1,j});
				vv.push_back({i,j});
			}
		}
		else if(i==0){
			if(a[i+1][j] == num){
				flag = true;
				vv.push_back({i+1,j});
				vv.push_back({i,j});	
			}
		}
		else{
			if(a[i-1][j] == num){
				flag = true;
				vv.push_back({i-1,j});
				vv.push_back({i,j});	
			}
			if(a[i+1][j] == num){
				flag = true;
				vv.push_back({i+1,j});	
				vv.push_back({i,j});
			}
		}	
	}
}

void averageV(){
	double avg = 0;
	double cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=-1){
				++cnt;
				avg+=a[i][j];
			}
		}
	}
	avg /= cnt;
	//cout<<"avg: "<<avg<<'\n';
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			double num = a[i][j];
			if(num!=-1){
				if(num>avg){
					--a[i][j];
				}
				if(num<avg){
					++a[i][j];
				}
			}
		}
	}
	//printCircle();
}
void go(int x, int d, int k){
	vv.clear();
	flag = false;
	vector<int> v;
	for(int i=0; i<n; i++){
		if((i+1)%x==0){
			v.push_back(i);
		}
	}
	for(int i=0; i<v.size();i++){
		if(d==0){
			rotate(a[v[i]],a[v[i]]+m-k,a[v[i]]+m);
		}
		else{
			rotate(a[v[i]],a[v[i]]+k,a[v[i]]+m);
		}
	}
	//printCircle();
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			clearCircle(i,j);
			//printCircle();
		}
	}
	for(int i=0; i<vv.size();i++){
		a[vv[i].first][vv[i].second]= -1;
	}
	if(!flag){
		averageV();
	}
	//printCircle();
}
int main(){
	cin>>n>>m>>t;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}
	for(int i=0; i<t; i++){
		//cout<<i<<"번째---------------------\n";
		cin>>x>>d>>k;
		go(x,d,k);
		//cout<<"---------------\n";
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j]!=-1){
				ret += a[i][j];
			}
		}
	}
	cout<<ret;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
string s;
struct student{
	string name;
	int day;
	int month;
	int year;
};
bool cmp(student a, student b){
	if(a.month == b.month && a.year == b.year) return a.day<b.day;
	if(a.year == b.year) return a.month < b.month;
	return a.year<b.year;
}
vector<student> v;
int main() {
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s>>a>>b>>c;
		v.push_back({s,a,b,c});
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v[v.size()-1].name<<"\n";
	cout<<v[0].name<<"\n";
  return 0;
}


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t,n;
string dp[1001];
bool check(string a,string b){
	//if(a=="" && b=="") return false;
	if(a == "") return true;
	if(a.size() == b.size()) return a>b;
	return a.size() > b.size();
}
char printchar(char c){
	if(c=='1') return '(';
	if(c=='2') return ')';
	if(c=='3') return '{';
	if(c=='4') return '}';
	if(c=='5') return '[';
	if(c=='6') return ']';
}
int main() {
	dp[1]="12";
	dp[2]="34";
	dp[3]="56";
	for(int i=4; i<=1000; i++){
		if(i%2==0 && check(dp[i],"1"+dp[i/2]+"2")) dp[i]="1"+dp[i/2]+"2";
		if(i%3==0 && check(dp[i],"3"+dp[i/3]+"4")) dp[i]="3"+dp[i/3]+"4";
		if(i%5==0 && check(dp[i],"5"+dp[i/5]+"6")) dp[i]="5"+dp[i/5]+"6";
		for(int idx=1; idx<=i; idx++){
			if(check(dp[i], dp[idx] + dp[i-idx])) dp[i]=dp[idx] + dp[i-idx];
		}
	}
    cin>>t;
    while(t--){
    	cin>>n;
    	for(char c : dp[n]){
    		cout<<printchar(c);
		}
		cout<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int t,n;
string dp[101],dp1[101];
int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const string MAX_STR = "111111111111111111111111111111111111111111111111119";
string cmp1(string s1, string s2){
	if(s1.size()==s2.size()){
		return s1<s2?s2:s1;
	}
	return s1.size()<s2.size()?s2:s1;
}
string cmp2(string s1, string s2){
	if(s1.size()==s2.size()){
		return s1<s2?s1:s2;
	}
	return s1.size()<s2.size()?s1:s2;
}
string go(int num){
	if(num == 0) return "";
	
	string &ret = dp[num];
	if(ret!="") return ret;
	
	if(num >= 2) ret = cmp1(ret,"1"+go(num-2));
	if(num >= 3) ret = cmp1(ret,"7"+go(num-3)); 
	if(num >= 4) ret = cmp1(ret,"4"+go(num-4));
	if(num >= 5){
		ret = cmp1(ret,"2"+go(num-5));
		ret = cmp1(ret,"3"+go(num-5));
		ret = cmp1(ret,"5"+go(num-5));
	}
	if(num >= 6){
		if(num != n) ret = cmp1(ret,"0"+go(num-6));
		ret = cmp1(ret,"6"+go(num-6));
		ret = cmp1(ret,"9"+go(num-6));
	}
	if(num >=7){
		ret = cmp1(ret,"8"+go(num-7));
	}
	
	return ret;
}
int main(){
	cin>>t;
	fill(dp1,dp1+101,MAX_STR);
	dp1[0]="";
	for(int i=2; i<101; i++){
		for(int j=0; j<=9; j++){
			if(i-a[j]<0) continue;
			if(j==0 && dp1[i-a[j]]=="") continue;
			dp1[i]=cmp2(dp1[i],dp1[i-a[j]]+to_string(j));
		}
	}
	for(int i=0; i<t; i++){
		cin>>n;
		cout<<dp1[n]<<" "<<go(n)<<"\n";
	}
}

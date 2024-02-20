#include<bits/stdc++.h>
using namespace std;
int n;
double ret,total1,total2;
int main(){
	for(int i=0; i<20; i++){
		string s,grade;
		double c;
		cin>>s>>c>>grade;
		if(grade.size()==2){
			if(grade[0]=='A'&&grade[1]=='+'){
			total1+=c*4.5;
			total2+=c;
		}
		else if(grade[0]=='A'&&grade[1]=='0'){
			total1+=c*4.0;
			total2+=c;
		}
		else if(grade[0]=='B'&&grade[1]=='+'){
			total1+=c*3.5;
			total2+=c;
		}
		else if(grade[0]=='B'&&grade[1]=='0'){
			total1+=c*3.0;
			total2+=c;
		}
		else if(grade[0]=='C'&&grade[1]=='+'){
			total1+=c*2.5;
			total2+=c;
		}
		else if(grade[0]=='C'&&grade[1]=='0'){
			total1+=c*2.0;
			total2+=c;
		}
		else if(grade[0]=='D'&&grade[1]=='+'){
			total1+=c*1.5;
			total2+=c;
		}
		else if(grade[0]=='D'&&grade[1]=='0'){
			total1+=c*1.0;
			total2+=c;
		}
		}
		else if(grade[0]=='F'){
			total2+=c;
		}
		ret=total1/total2;
	}
	cout<<ret;
return 0;
}


#include<bits/stdc++.h>
using namespace std;
int m,n;
int ret;
char s[11];
int count;
int main(){
	cin >> m;
	for(int i=0; i<m; i++){
		scanf("%s %d",&s,&n);
		if(s[0]=='a'&&s[1]=='d'){
			ret |= (1<<n);
		}
		else if(s[0]=='r'){
			ret &= ~(1<<n);
		}
		else if(s[0]=='c'){
			printf("%d\n",(ret&(1<<n)) == 0 ? 0:1);
		}
		else if (s[0]=='t'){
			ret ^= (1<<n);
		}
		else if(s[0]=='a'&&s[1]=='l'){
			ret=(1<<21)-1;
		}
		else if(s[0]=='e'){
			ret=0;
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<bits/stdc++.h>

using namespace std;
int pibo[103];
int n;


bool canDivide(int n, vector<char> &result) {
    int totalSum = 0;
    for(int i = 1; i <= n; i++) {
        totalSum += pibo[i];
    }
    if(totalSum % 2 != 0) {
        return false; // 총합이 홀수이면 나눌 수 없음
    }

    int target = totalSum / 2;
    result.assign(n, 'B'); // 기본적으로 모두 집합 B에 포함
    for(int i = n; i >= 1; i--) {
        if(target >= pibo[i]) {
            target -= pibo[i];
            result[i - 1] = 'A'; // 집합 A에 포함
        }
    }
    return (target == 0);
}
void printResult(int n, int idx){
    for(int i=0; i<n; i++){
        if(idx >= i) cout<<"B";
        else cout<<"A";
    }
    cout<<"\n";
}
void printResult(int n) {
    if (n % 3 == 1) {
        cout << "impossible\n"; // 나머지가 1인 경우 분해 불가
        return;
    }

    string result;
    if (n % 3 == 0) {
        // BBA 패턴 반복
        for (int i = 0; i < n / 3; i++) {
            result += "BBA";
        }
    } else if (n % 3 == 2) {
        // BA + BBA 패턴 반복
        result += "BA";
        for (int i = 0; i < n / 3; i++) {
            result += "BBA";
        }
    }
    cout << result << "\n";
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
  
    pibo[0]=1;
    pibo[1]=1;
    for(int i=2; i<100; i++){
        pibo[i]= pibo[i-2]+pibo[i-1];
    }
        
	for(int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;
        printResult(n);
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
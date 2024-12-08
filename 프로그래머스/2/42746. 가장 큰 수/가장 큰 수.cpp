#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a; // 결합 후 더 큰 문자열 순서로 정렬
}

string solution(vector<int> numbers) {
    vector<string> a;
    for (int number : numbers) {
        a.push_back(to_string(number)); // 숫자를 문자열로 변환하여 저장
    }
    sort(a.begin(), a.end(), cmp); // 사용자 정의 비교 함수로 정렬

    // 결과 문자열 생성
    string answer = "";
    for (string s : a) {
        answer += s;
    }

    // 0으로만 구성된 경우 처리
    if (answer[0] == '0') {
        return "0";
    }

    return answer;
}

#include <bits/stdc++.h>

using namespace std;
bool visited[10000000];
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    set<int> uniqueNumbers;
    
    // 모든 숫자 조합을 생성하여 set에 추가
    sort(numbers.begin(), numbers.end());
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            uniqueNumbers.insert(num);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    // 각 숫자가 소수인지 확인
    for (int num : uniqueNumbers) {
        if (isPrime(num)) {
            answer++;
        }
    }
    return answer;
}
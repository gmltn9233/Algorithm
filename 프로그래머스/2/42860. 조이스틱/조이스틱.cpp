#include<bits/stdc++.h>
using namespace std;

int solution(string name) {
    int answer = 0;
    int move = name.size() - 1; // 최대 이동값을 우선 name 크기 - 1로 설정

    for (int i = 0; i < name.size(); ++i) {
        // 해당 문자를 'A'로 만드는 최소 조작 횟수
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);

        // 현재 위치부터 연속된 'A'를 계산
        int next = i + 1;
        while (next < name.size() && name[next] == 'A') next++;

        // 이동을 최소화하는 계산: 오른쪽으로 쭉 가는 경우와 왼쪽으로 돌아가는 경우를 비교
        move = min(move, i + (int)name.size() - next + min(i, (int)name.size() - next));
    }

    return answer + move;
}

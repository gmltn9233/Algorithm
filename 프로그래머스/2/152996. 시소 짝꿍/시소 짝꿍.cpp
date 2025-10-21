#include <bits/stdc++.h>
using namespace std;

long long solution(vector<int> weights) {
    map<int,int> mp;
    long long answer = 0;

    for (int w : weights) {
        answer += mp[w];               // 1:1
        if (w % 2 == 0) answer += mp[w / 2];     // 1:2
        answer += mp[w * 2];                     // 2:1
        if ((w * 2) % 3 == 0) answer += mp[w * 2 / 3]; // 2:3
        if ((w * 3) % 2 == 0) answer += mp[w * 3 / 2]; // 3:2
        if ((w * 3) % 4 == 0) answer += mp[w * 3 / 4]; // 3:4
        if ((w * 4) % 3 == 0) answer += mp[w * 4 / 3]; // 4:3

        mp[w]++;
    }

    return answer;
}
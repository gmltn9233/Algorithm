#include <bits/stdc++.h>

using namespace std;
int a[51][51];
map<string, int> mp;
int score[51];
int gift[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for (int i = 0; i < friends.size(); i++) {
        mp[friends[i]] = i;
    }
    for (string s : gifts) {
        string s1, s2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                s1 = s.substr(0, i);
                s2 = s.substr(i + 1); // 공백 이후부터 끝까지 추출
                break;
            }
        }
        a[mp[s1]][mp[s2]]++;
        score[mp[s1]]++;
        score[mp[s2]]--;
    }

    for (int i = 0; i < friends.size(); i++) {
        for (int j = i + 1; j < friends.size(); j++) {
            if (a[i][j] == 0 && a[j][i] == 0) {
                // 주고받은 기록이 없는 경우
                if (score[i] > score[j]) {
                    gift[i]++;
                } else if (score[i] < score[j]) {
                    gift[j]++;
                }
            } else if (a[i][j] == a[j][i]) {
                // 주고받은 횟수가 같은 경우
                if (score[i] > score[j]) {
                    gift[i]++;
                } else if (score[i] < score[j]) {
                    gift[j]++;
                }
            } else {
                // 주고받은 횟수가 다른 경우
                if (a[i][j] > a[j][i]) {
                    gift[i]++;
                } else {
                    gift[j]++;
                }
            }
        }
    }

    for (int i = 0; i < friends.size(); i++) {
        answer = max(answer, gift[i]);
    }
    return answer;
}

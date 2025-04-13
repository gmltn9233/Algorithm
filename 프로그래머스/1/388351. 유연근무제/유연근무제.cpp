#include <bits/stdc++.h>
using namespace std;

int get_limit(int schedule) {
    int hour = schedule / 100;
    int minute = schedule % 100;
    minute += 10;
    if (minute >= 60) {
        hour += 1;
        minute -= 60;
    }
    return hour * 100 + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++) {
        int limit = get_limit(schedules[i]);
        bool fail = false;
        for (int j = 0; j < 7; j++) {
            int day = (startday - 1 + j) % 7 + 1;
            if (day == 6 || day == 7) continue; // 토, 일 제외
            if (timelogs[i][j] > limit) {
                fail = true;
                break;
            }
        }
        if (!fail) ++answer;
    }
    return answer;
}
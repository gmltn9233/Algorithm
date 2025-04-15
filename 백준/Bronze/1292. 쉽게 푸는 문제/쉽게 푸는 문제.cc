#include <bits/stdc++.h>
using namespace std;

int a, b, ret;
int main()
{
    cin >> a >> b;

    int idx = 1;  // 현재 숫자
    int cnt = 0;  // 현재까지 몇 개의 수를 출력했는지
    for (int i = 1; cnt < b; i++) {
        for (int j = 0; j < i; j++) {
            cnt++;
            if (cnt >= a && cnt <= b) {
                ret += i;
            }
        }
    }

    cout << ret << endl;
    return 0;
}
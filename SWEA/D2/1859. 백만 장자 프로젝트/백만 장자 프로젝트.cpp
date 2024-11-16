#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int N;
        cin >> N;
        vector<int> prices(N);
        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        long long maxProfit = 0;
        int maxPrice = 0;

        // 뒤에서부터 최대 가격을 갱신하며 이익을 계산
        for (int i = N - 1; i >= 0; --i) {
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
            } else {
                maxProfit += maxPrice - prices[i];
            }
        }

        cout << "#" << test_case << " " << maxProfit << "\n";
    }
    return 0;
}

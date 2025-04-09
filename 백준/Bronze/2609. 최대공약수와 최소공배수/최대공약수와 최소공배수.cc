#include <bits/stdc++.h>
using namespace std;

int a, b;

int gcd(int x, int y) {
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int lcm(int x, int y) {
    return x * y / gcd(x, y);  // 반드시 GCD 먼저 구해서 나눠야 오버플로 방지됨
}

int main() {
    cin >> a >> b;
    cout << gcd(a, b) << "\n";
    cout << lcm(a, b) << "\n";
    return 0;
}
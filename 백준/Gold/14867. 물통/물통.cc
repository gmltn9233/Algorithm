#include <bits/stdc++.h> 
using namespace std;

const int INF = 987654321;
int a, b, c, d;
map<pair<int, int>, int> m;

int go(int b1, int b2) {
    if (b1 == c && b2 == d) {
        return 1;
    }
    
    if (m.find({b1, b2}) != m.end()) {
        return m[{b1, b2}];
    }
    
    int &ret = m[{b1, b2}];
    ret = INF;
    
    ret = min(ret, 1 + go(a, b2)); // Fill jug 1
    ret = min(ret, 1 + go(b1, b)); // Fill jug 2
    ret = min(ret, 1 + go(0, b2)); // Empty jug 1
    ret = min(ret, 1 + go(b1, 0)); // Empty jug 2
    
    if (a - b1 >= b2) {
        ret = min(ret, 1 + go(b1 + b2, 0)); // Pour jug 2 into jug 1
    } else {
        ret = min(ret, 1 + go(a, b2 - (a - b1))); // Pour jug 2 into jug 1 until jug 1 is full
    }
    
    if (b - b2 >= b1) {
        ret = min(ret, 1 + go(0, b1 + b2)); // Pour jug 1 into jug 2
    } else {
        ret = min(ret, 1 + go(b1 - (b - b2), b)); // Pour jug 1 into jug 2 until jug 2 is full
    }
    
    return ret;
}

int main() {
    cin >> a >> b >> c >> d;
    int num = go(0, 0);
    num = num == INF ? -1 : num - 1;
    cout << num << '\n';
    
    return 0;
}

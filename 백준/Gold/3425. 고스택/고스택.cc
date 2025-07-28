#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;
vector<string> cmds;
vector<long long> nums;

bool execute(long long start) {
    stack<long long> st;

    st.push(start);

    int idx = 0;
    for (string cmd : cmds) {
        if (cmd == "NUM") {
            st.push(nums[idx++]);
        } 
        else if (cmd == "POP") {
            if (st.empty()) return false;
            st.pop();
        } 
        else if (cmd == "INV") {
            if (st.empty()) return false;
            long long x = st.top(); st.pop();
            st.push(-x);
        } 
        else if (cmd == "DUP") {
            if (st.empty()) return false;
            st.push(st.top());
        } 
        else if (cmd == "SWP") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            st.push(a); st.push(b);
        } 
        else if (cmd == "ADD") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            long long res = a + b;
            if (abs(res) > INF) return false;
            st.push(res);
        } 
        else if (cmd == "SUB") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            long long res = b - a;
            if (abs(res) > INF) return false;
            st.push(res);
        } 
        else if (cmd == "MUL") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            long long res = a * b;
            if (abs(res) > INF) return false;
            st.push(res);
        } 
        else if (cmd == "DIV") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            if (a == 0) return false;
            long long res = abs(b) / abs(a);
            if ((b < 0) ^ (a < 0)) res = -res;
            if (abs(res) > INF) return false;
            st.push(res);
        } 
        else if (cmd == "MOD") {
            if (st.size() < 2) return false;
            long long a = st.top(); st.pop();
            long long b = st.top(); st.pop();
            if (a == 0) return false;
            long long res = abs(b) % abs(a);
            if (b < 0) res = -res;
            if (abs(res) > INF) return false;
            st.push(res);
        }
    }

    if (st.size() != 1) return false;

    cout << st.top() << "\n";
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cmds.clear();
        nums.clear();
        string cmd;
        while (cin >> cmd) {
            if (cmd == "QUIT") return 0;
            if (cmd == "END") break;
            cmds.push_back(cmd);
            if (cmd == "NUM") {
                long long x; cin >> x;
                nums.push_back(x);
            }
        }

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (!execute(x)) cout << "ERROR\n";
        }
        cout << "\n";
    }
    return 0;
}
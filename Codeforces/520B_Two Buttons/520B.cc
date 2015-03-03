#include <bits/stdc++.h>

using namespace std;

struct Node {
    int n, t;
    Node() = default;
    Node(int _n, int _t) : n(_n), t(_t) {}
};

int main() {
    int n, m;
    cin >> n >> m;

    queue<Node> q;
    set<int> s;
    q.push(Node(n, 0));
    s.insert(n);

    while (not q.empty()) {
        int _n = q.front().n, _t = q.front().t;
        q.pop();

        if (_n * 2 == m or _n - 1 == m) {
            cout << _t + 1 << endl;
            break;
        }

        if (_n < m and s.find(_n * 2) == s.end()) {
            q.push(Node(_n * 2, _t + 1));
            s.insert(_n * 2);
        }

        if (_n - 1 > 0) {
            q.push(Node(_n - 1, _t + 1));
            s.insert(_n - 1);
        }
    }

    return 0;
}


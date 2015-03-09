#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Node {
    int s, n, m, t;
    Node() {}
    Node(int _s, int _n, int _m, int _t) : s(_s), n(_n), m(_m), t(_t) {}
};

int hash(int s, int n, int m) {
    return s * 10000 + n * 100 + m;
}

int bfs(int s_max, int n_max, int m_max) {
    set<int> s;
    queue<Node> q;

    q.push(Node(s_max, 0, 0, 0));
    s.insert(hash(s_max, 0, 0));

    while (not q.empty()) {
        int _s = q.front().s;
        int _n = q.front().n;
        int _m = q.front().m;
        int _t = q.front().t;
        q.pop();

        if (_s == 0 and _n == _m or _n == 0 and _s == _m or _m == 0 and _s == _n)
            return _t;
    
        int new_s, new_n, new_m, new_t = _t + 1;
        
        // S -> N
        new_s = _s - min(n_max - _n, _s);
        new_n = min(_s + _n, n_max);
        new_m = _m;
        if (_s and _n < n_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }
        // S -> M
        new_s = _s - min(m_max - _m, _s);
        new_n = _n;
        new_m = min(_s + _m, m_max);
        if (_s and _m < m_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }

        // N -> S
        new_s = min(_s + _n, s_max);
        new_n = _n - min(s_max - _s, _n);
        new_m = _m;
        if (_n and _s < s_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }
        // N -> M
        new_s = _s;
        new_n = _n - min(m_max - _m, _n);
        new_m = min(_n + _m, m_max);
        if (_n and _m < m_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }

        // M -> S
        new_s = min(_s + _m, s_max);
        new_n = _n;
        new_m = _m - min(s_max - _s, _m);
        if (_m and _s < s_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }
        // M -> N
        new_s = _s;
        new_n = min(_n + _m, n_max);
        new_m = _m - min(n_max - _n, _m);
        if (_m and _n < n_max and s.find(hash(new_s, new_n, new_m)) == s.end()) {
            q.push(Node(new_s, new_n, new_m, new_t));
            s.insert(hash(new_s, new_n, new_m));
        }
    }

    return -1;
}

int main() {
    int s, n, m;
    while (cin >> s >> n >> m and s + n + m) {
        int ans = bfs(s, n, m);
        if (ans == -1)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}


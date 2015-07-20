#include <bits/stdc++.h>

using namespace std;

int n;
double d[100];

struct Edge {
    int u, v;
    double p;
    Edge() {}
    Edge(int _u, int _v, double _p) : u(_u), v(_v), p(_p) {}
};

vector <Edge> e;

void bellman_ford() {
    d[0] = 1;
    for (int i = 1; i < n; ++i)
        d[i] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < e.size(); ++j) {
            d[e[j].v] = max(d[e[j].v], d[e[j].u] * e[j].p);
            d[e[j].u] = max(d[e[j].u], d[e[j].v] * e[j].p);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int m, s, k;
        cin >> n >> m >> s >> k;
        e.clear();
        for (int i = 0; i < m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            e.push_back(Edge(u, v, p / 100.0));
        }
        bellman_ford();
        cout << "Case " << cases << ": "
             << setprecision(6) << fixed << (2 * k / d[n-1]) * s << endl;
    }
    return 0;
}


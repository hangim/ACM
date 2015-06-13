#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v, cap, rev;
    Edge (int _v, int _c, int _r) : v(_v), cap(_c), rev(_r) {}
};

const int MAXN = 210;
const int INF = 1e8;
vector<Edge> E[MAXN];
bool used[MAXN];

int dfs(int s, int t, int f) {
    if (s == t)
        return f;
    used[s] = true;
    for (int i = 0; i != E[s].size(); ++i) {
        int &v = E[s][i].v, &cap = E[s][i].cap, &rev = E[s][i].rev;
        if (not used[v] and cap > 0) {
            int d = dfs(v, t, min(f, cap));
            if (d > 0) {
                cap -= d;
                E[v][rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0, f = 0;
    do {
        memset(used, 0, sizeof(used));
        f = dfs(s, t, INF);
        flow += f;
    } while (f != 0);
    return flow;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i != MAXN; ++i)
            E[i].clear();
        for (int i = 0; i != n; ++i) {
            int u, v, cap;
            cin >> u >> v >> cap;
            E[u].push_back(Edge(v, cap, E[v].size()));
            E[v].push_back(Edge(u, 0, E[u].size() - 1));
        }
        cout << max_flow(1, m) << endl;
    }
    return 0;
}


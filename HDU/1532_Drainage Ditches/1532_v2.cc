#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;
const int MAXN = 210;
int flow[MAXN][MAXN], cap[MAXN][MAXN], pre[MAXN], d[MAXN];

int EK(int s, int t, int n) {
    int maxFlow = 0;
    memset(flow, 0, sizeof(flow));
    memset(pre, 0, sizeof(pre));
    do {
        memset(d, 0, sizeof(d));
        queue<int> q;
        d[s] = INF;
        q.push(s);
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; ++v) {
                if (d[v] == 0 and cap[u][v] > flow[u][v]) {
                    pre[v] = u;
                    d[v] = min(d[u], cap[u][v] - flow[u][v]);
                    q.push(v);
                }
            }
        }
        for (int u = t; u != s; u = pre[u]) {
            flow[pre[u]][u] += d[t];
            flow[u][pre[u]] -= d[t];
        }
        maxFlow += d[t];
    } while (d[t] != 0);
    return maxFlow;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        memset(cap, 0, sizeof(cap));
        for (int i = 0; i != n; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            cap[u][v] += c;
        }
        cout << EK(1, m, m) << endl;
    }
    return 0;
}


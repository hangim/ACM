#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;
const int MAXM = 510;
const int INF = 0x3FFFFFFF;
const int src = 1, dst = 2;

int n, m;
int g[MAXN][MAXN], pre[MAXN], flow[MAXN];

int bfs() {
    memset(flow, 0, sizeof(flow));
    memset(pre, -1, sizeof(pre));

    queue<int> q;
    q.push(src);
    pre[src] = src;
    flow[src] = INF;

    while (not q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dst)
            break;
        for (int v = 1; v <= n; ++v) {
            if (pre[v] == -1 and g[u][v]) {
                pre[v] = u;

                flow[v] = min(flow[u], g[u][v]);
                q.push(v);
            }
        }
    }

    return pre[dst] == -1 ? -1 : flow[dst];
}

int Edmonds_Karp() {
    int max_flow = 0, res;
    while ((res = bfs()) != -1) {
        max_flow += res;
        for (int u = dst; u != src; u = pre[u]) {
            g[pre[u]][u] -= res;
            g[u][pre[u]] += res;
        }
    }
    return max_flow;
}

int x[MAXM], y[MAXM];

int main() {
    while (cin >> n >> m and n + m) {
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= m; ++i) {
            cin >> x[i] >> y[i];
            cin >> g[x[i]][y[i]];
            g[y[i]][x[i]] = g[x[i]][y[i]];
        }
        Edmonds_Karp();
        for (int i = 1; i <= m; ++i) {
            if ((not flow[x[i]] and flow[y[i]])
                or (flow[x[i]] and not flow[y[i]])) {
                cout << x[i] << " " << y[i] << endl;
            }
        }
        cout << endl;
    }
    return 0;
}


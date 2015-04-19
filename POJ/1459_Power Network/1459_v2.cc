#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 210;
const int INF = 0x3FFFFFFF;
int cap[MAXN][MAXN], flow[MAXN], pre[MAXN], src, dst, N;

int bfs() {
    memset(pre, -1, sizeof(flow));
    queue<int> q;
    q.push(src);
    flow[src] = INF;
    pre[src] = 0;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dst)
            break;
        for (int v = 0; v <= N; ++v) {
            if (pre[v] == -1 and cap[u][v]) {
                flow[v] = min(flow[u], cap[u][v]);
                pre[v] = u;
                q.push(v);
            }
        }
    }
    return pre[dst] != -1 ? flow[dst] : 0;
}

int Edmonds_Karp() {
    int max_flow = 0, f;
    while ((f = bfs()) != 0) {
        max_flow += f;
        for (int u = dst; u != src; u = pre[u]) {
            cap[pre[u]][u] -= f;
            cap[u][pre[u]] += f;
        }
    }
    return max_flow;
}

int main() {
    int n, np, nc, m;
    while (scanf("%d %d %d %d", &n, &np, &nc, &m) != EOF) {
        src = n, N = dst = n + 1;
        memset(cap, 0, sizeof(cap));

        for (int i = 0; i != m; ++i) {
            int u, v, z;
            scanf(" (%d,%d)%d", &u, &v, &z);
            cap[u][v] = z;
        }
        for (int i = 0; i != np; ++i) {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[src][u] = z;
        }
        for (int i = 0; i != nc; ++i) {
            int u, z;
            scanf(" (%d)%d", &u, &z);
            cap[u][dst] = z;
        }
        printf("%d\n", Edmonds_Karp());
    }
    return 0;
}


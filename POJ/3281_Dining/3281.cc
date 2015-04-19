#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 410;
const int INF = 0x3FFFFFFF;
int g[MAXN][MAXN], flow[MAXN], path[MAXN];
int n;

int bfs() {
    memset(path, -1, sizeof(path));
    flow[0] = INF;

    queue<int> q;
    q.push(0);
    while (not q.empty()) {
        int t = q.front();
        q.pop();
        if (t == n)
            break;
        for (int i = 1; i <= n; ++i) {
            if (path[i] == -1 and g[t][i]) {
                flow[i] = min(flow[t], g[t][i]);
                path[i] = t;
                q.push(i);
            }
        }
    }
    if (path[n] == -1)
        return -1;
    return flow[n];
}

int Edmonds_Karp() {
    int max_flow = 0, d, now, pre;
    while ((d = bfs()) != -1) {
        max_flow += d;
        now = n;
        while (now != 0) {
            pre = path[now];
            g[pre][now] -= d;
            g[now][pre] += d;
            now = pre;
        }
    }
    return max_flow;
}

int main() {
    int N, F, D;
    cin >> N >> F >> D;
    n = F + 2 * N + D + 1;

    // 源点到食物 0 -> [1..F]
    for (int i = 1; i <= F; ++i)
        g[0][i] = 1;

    // 把牛拆分为2个点 [F+1..F+N] -> [F+N+1..F+2N]
    for (int i = F + 1; i <= F + N; ++i)
        g[i][i+N] = 1;

    // 水到汇点 [F+2N+1..F+2N+D] -> F+2N+D+1
    for (int i = F + 2 * N + 1; i != n; ++i)
        g[i][n] = 1;

    for (int i = 1; i <= N; ++i) {
        int f, d, t;
        cin >> f >> d;
        while (f--) {
            cin >> t;
            g[t][F+i] = 1; // 食物到牛
        }
        while (d--) {
            cin >> t;
            g[F+N+i][F+2*N+t] = 1; // 牛到水
        }
    }
    cout << Edmonds_Karp() << endl;
    return 0;
}


#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 110;
const int INF = 0x3FFFFFFF;
int cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];

int n, f, c, src, dst;

bool vis[MAXN];
int pre[MAXN], dist[MAXN];

bool SPFA() {
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i <= n; ++i)
        dist[i] = INF;

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    vis[src] = true;
    while (not q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int v = 0; v <= n; ++v) {
            if (cap[u][v] > flow[u][v] and dist[v] > dist[u] + cost[u][v]) {
                dist[v] = dist[u] + cost[u][v];
                pre[v] = u;
                if (not vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return dist[dst] < INF;
}

void minCostMaxFlow() {
    memset(flow, 0, sizeof(flow));
    c = f = 0;
    while (SPFA()) {
        int MIN = INF;
        for (int u = dst; u != src; u = pre[u])
            MIN = min(MIN, cap[pre[u]][u] - flow[pre[u]][u]);
        for (int u = dst; u != src; u = pre[u]) {
            flow[pre[u]][u] += MIN;
            flow[u][pre[u]] -= MIN;
        }
        c += dist[dst] * MIN;
        f += MIN;
    }
}

int order[MAXN][MAXN], supply[MAXN][MAXN], tolorder[MAXN];

int main() {
    int N, M, K;
    while (cin >> N >> M >> K and N + M + K) {
        src = 0, n = dst = N + M + 1;
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));

        for (int i = 1; i <= N; ++i) // 需求量
            for (int j = 1; j <= K; ++j)
                cin >> order[i][j];

        for (int i = 1; i <= M; ++i) // 供应量
            for (int j = 1; j <= K; ++j)
                cin >> supply[i][j];

        for (int i = 1; i <= K; ++i) { // 需求量合计
            tolorder[i] = 0;
            for (int j = 1; j <= N; ++j)
                tolorder[i] += order[j][i];
        }

        for (int i = 1; i <= M; i++) { // 仓库 -> 店主
            for (int j = 1; j <= N; ++j) {
                cap[i][M+j] = INF;
            }
        }

        bool flag = true;
        int ans = 0;
        for (int k = 1; k <= K; ++k) { // 第k件商品
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    cin >> cost[j][M+i];
                    cost[M+i][j] = -cost[j][M+i];
                }
            }
            for (int i = 1; i <= M; ++i)
                cap[src][i] = supply[i][k]; // 供应量
            for (int i = 1; i <= N; ++i)
                cap[M+i][dst] = order[i][k]; // 需求量

            minCostMaxFlow();
            if (f < tolorder[k])
                flag = false;
            else
                 ans += c;
        }

        if (flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}


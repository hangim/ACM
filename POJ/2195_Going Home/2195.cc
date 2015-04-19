#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXN = 210;
const int INF = 1e9;
int cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
int n, f, c, src, dst;

bool vis[MAXN];
int pre[MAXN], dist[MAXN];

bool SPFA() {
    for (int i = 0; i <= n; ++i) {
        dist[i] = INF;
        vis[i] = false;
    }

    dist[src] = 0;
    vis[src] = true;
    queue<int> q;
    q.push(src);

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

void min_cost_max_flow() {
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

struct Node {
    int x, y;
} house[MAXN], man[MAXN];

int main() {
    int N, M;
    while (cin >> N >> M and N + M) {
        int tol1 = 0, tol2 = 0;
        for (int i = 0; i != N; ++i) {
            string str;
            cin >> str;
            for (int j = 0; j != M; ++j) {
                if (str[j] == 'm') {
                    ++tol1;
                    man[tol1].x = i;
                    man[tol1].y = j;
                } else if (str[j] == 'H') {
                    ++tol2;
                    house[tol2].x = i;
                    house[tol2].y = j;
                }
            }
        }

        src = 0;
        dst = n = tol1 + tol2 + 1;
        memset(cap, 0, sizeof(cap));
        memset(cost, 0, sizeof(cost));
        for (int i = 1; i <= tol1; ++i) {
            cap[src][i] = 1;
            for (int j = 1; j <= tol2; ++j) {
                cost[i][tol1 + j] = abs(house[i].x - man[j].x) + 
                    abs(house[i].y - man[j].y);
                cost[tol1 + j][i] = -cost[i][tol1 + j];
                cap[i][tol1 + j] = 1;
            }
        }
        for (int j = 1; j <= tol2; ++j) {
            cap[tol1 + j][dst] = 1;
        }
        min_cost_max_flow();
        cout << c << endl;
    }
    return 0;
}


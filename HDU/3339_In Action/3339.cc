#include <bits/stdc++.h>

using namespace std;

int n, m;
struct Edge {
    int u, v, c;
} e[10010];
int dist[110];
const int INF = 0x3FFFFFFF;

int power[110];
int dp[10110];

void bellman_ford() {
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;
    dist[0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[e[j].v] = min(dist[e[j].v], dist[e[j].u] + e[j].c);
            dist[e[j].u] = min(dist[e[j].u], dist[e[j].v] + e[j].c);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &power[i]);
            sum += power[i];
        }

        bellman_ford();

        for (int i = 1; i <= sum; ++i)
            dp[i] = INF;
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INF)
                continue;
            for (int j = sum; j >= power[i]; --j) {
                dp[j] = min(dp[j], dp[j-power[i]] + dist[i]);
            }
        }

        int ans = INF;
        for (int i = sum / 2 + 1; i <= sum; ++i) {
            ans = min(ans, dp[i]);
        }
        if (ans == INF)
            puts("impossible");
        else
            printf("%d\n", ans);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n;
int g[15][15];
double dp[15][1<<15];
int vis[15][1<<15];

bool dfs(int u, int sta) {
    if (sta == (1<<n) - 1) {
        dp[u][sta] = 0;
        return true;
    }
    if (vis[u][sta])
        return dp[u][sta] > 0;

    vis[u][sta] = 1;

    double ans = 0;
    int cnt = 0;
    for (int v = 0; v < n; ++v) {
        if ((sta & (1<<v)) == 0 and g[u][v] and dfs(v, sta | (1<<v))) {
            ans += g[u][v] + dp[v][sta | (1<<v)];
            ++cnt;
        }
    }

    if (cnt) {
        dp[u][sta] = (ans + 5) / cnt;
        return true;
    } else {
        dp[u][sta] = 0;
        return false;
    }
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int m;
        cin >> n >> m;
        memset(g, 0, sizeof(g));
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u][v] = g[v][u] = w;
        }
        memset(vis, 0, sizeof(vis));
        dfs(0, 1);
        cout << "Case " << cases << ": "
             << setprecision(6) << fixed<< dp[0][1] << endl;
    }
    return 0;
}


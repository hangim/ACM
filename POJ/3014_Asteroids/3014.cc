#include <iostream>
#include <cstring>

using namespace std;

int n;
int adj[501][501];

int pre[501];
int vis[501];

bool dfs(int u) {
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] and not vis[v]) {
            vis[v] = 1;
            if (pre[v] == -1 or dfs(pre[v])) {
                pre[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary() {
    int ans = 0;
    memset(pre, -1, sizeof(pre));
    for (int u = 1; u <= n; u++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(u))
            ans++;
    }
    return ans;
}

int main() {
    int k;
    cin >> n >> k;

    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    cout << hungary() << endl;

    return 0;
}


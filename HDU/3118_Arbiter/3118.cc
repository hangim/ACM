#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3FFFFFFF;
int N, M;
int adj[20][20];
int sta[20];
int ans;

void dfs(int u, int cnt) {
    if (u == N) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < 2; ++i) {
        sta[u] = i;
        int tmp = cnt;
        for (int j = 0; j != u; ++j)
            if (sta[u] == sta[j] and adj[j][u])
                tmp += adj[j][u];
        dfs(u + 1, tmp);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(adj, 0, sizeof(adj));
        cin >> N >> M;
        for (int i = 0; i != M; ++i) {
            int u, v;
            cin >> u >> v;
            ++adj[u][v];
            ++adj[v][u];
        }
        ans = INF;
        dfs(0, 0);
        cout << ans << endl;
    }
    return 0;
}


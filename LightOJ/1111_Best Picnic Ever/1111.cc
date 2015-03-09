#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

vector<int> e[1001];
int cnt[1001];
int vis[1001];

void dfs(int u) {
    ++cnt[u];
    vis[u] = 1;
    for (int i = 0; i != e[u].size(); ++i) {
        int v = e[u][i];
        if (vis[v] == 0)
            dfs(v);
    }
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        for (int i = 1; i <= 1000; ++i)
            e[i].clear();

        int k, n, m;
        cin >> k >> n >> m;
        
        set<int> init;
        for (int i = 0; i < k; ++i) {
            int u;
            cin >> u;
            init.insert(u);
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
        }

        memset(cnt, 0, sizeof(cnt));
        for (set<int>::iterator it = init.begin(); it != init.end(); ++it) {
            memset(vis, 0, sizeof(vis));
            dfs(*it);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == init.size())
                ++ans;
        }
        cout << "Case " << cases << ": " << ans << endl;
    }

    return 0;
}

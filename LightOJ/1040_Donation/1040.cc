#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1e9;

int n;
int e[50][50];
int vis[50], D[50];

int prim(int u) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i != n; ++i)
        D[i] = INF;

    D[u] = 0;
    int ans = 0;
    while (u != -1) {
        vis[u] = 1;
        ans += D[u];

        for (int i = 0; i != n; ++i) {
            if (i != u and vis[i] == 0) {
                if (e[u][i] != 0)
                    D[i] = min(D[i], e[u][i]);
                if (e[i][u] != 0)
                    D[i] = min(D[i], e[i][u]);
            }
        }

        u = -1;
        for (int i = 0; i != n; ++i) {
            if (vis[i] == 0 and D[i] != INF and (u == -1 or D[i] < D[u]))
                u = i;
        }
    }

    for (int i = 0; i != n; ++i) {
        if (D[i] == INF)
            return -1;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        cin >> n;
        int sum = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                cin >> e[i][j];
                sum += e[i][j];
            }
        }

        int ans = prim(0);

        cout << "Case " << cases << ": ";
        if (ans == -1)
            cout << -1 << endl;
        else
            cout << sum - ans << endl;
    }

    return 0;
}


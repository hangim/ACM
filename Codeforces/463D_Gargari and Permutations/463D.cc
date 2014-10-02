#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int pos[5][1001];
int best[1001];
int ans;
vector<int> e[1001];

void dfs(int u) {
    if (best[u] != -1)
        return;
    best[u] = 1;

    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i];
        dfs(v);
        best[u] = max(best[u], best[v] + 1);
    }

    ans = max(ans, best[u]);
}

int main() {
    memset(best, -1, sizeof(best));
    ans = 0;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            pos[i][v] = j;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            bool flag = true;
            for (int t = 0; t < k; t++) {
                if (pos[t][i] > pos[t][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                e[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
        dfs(i);

    cout << ans << endl;

    return 0;
}


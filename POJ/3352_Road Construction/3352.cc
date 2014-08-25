#include <iostream>
#include <vector>

using namespace std;

vector<int> e[1001];

int dfn[1001] = {0}, low[1001] = {0}, index = 1;
void tarjan(int u, int p) {
    dfn[u] = low[u] = index++;
    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i];
        if (v == p)
            continue;
        if (dfn[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main() {
    int n, r, u, v;
    cin >> n >> r;
    for (int i = 0; i < r; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    tarjan(1, 1);

    int in_degree[1001] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            int &v = e[i][j];
            if (low[i] != low[v])
                in_degree[low[v]]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 1)
            ans++;
    }
    cout << (ans + 1) / 2 << endl;

    return 0;
}


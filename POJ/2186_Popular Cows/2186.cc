#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> e[10001];

int dfn[10001] = {0}, low[10001] = {0}, index = 1;
int belong[10001] = {0}, index_b = 1;
stack<int> s;

void tarjan(int u) {
    s.push(u);

    dfn[u] = low[u] = index++;
    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i];
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    if (dfn[u] == low[u]) {
        int x;
        do {
            x = s.top();
            s.pop();
            belong[x] = index_b;
        } while (x != u);
        index_b++;
    }
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        if (dfn[i] == 0)
            tarjan(i);
    }

    int cnt[10001] = {0}, out_degree[10001] = {0};
    for (int i = 1; i <= n; i++) {
        cnt[belong[i]]++;
        for (int j = 0; j < e[i].size(); j++) {
            int &v = e[i][j];
            if (belong[i] != belong[v])
                out_degree[belong[i]]++;
        }
    }

    int ans = 0;
    int ans_count = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 0 and out_degree[i] == 0) {
            ans = cnt[i];
            ans_count++;
        }
    }

    if (ans_count == 1)
        cout << ans << endl;
    else
        cout << 0 << endl;

    return 0;
}


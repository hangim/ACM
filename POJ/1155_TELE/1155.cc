#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 1 << 29;

int n, m;
int dp[3001][3001];
int num[3001];

struct Edge {
    int v;
    int w;
};

vector<struct Edge> e[3001];

using namespace std;

void init(int u) {
    if (u > n-m) {
        num[u] = 1;
        return;
    }

    if (num[u] > 0)
        return;

    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i].v;
        init(v);
        num[u] += num[v];
    }
}

void dfs(int u) {
    if (u > n-m)
        return;

    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i].v;
        int &w = e[u][i].w;
        dfs(v);

        for (int j = num[u]; j >= 1; j--) {
            for (int k = 1; k <= j; k++)
                dp[u][j] = max(dp[u][j], dp[u][j-k] + dp[v][k] - w);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            dp[i][j] = -INF;
    }
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    memset(num, 0, sizeof(num));
    
    for (int i = 1; i <= n-m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            struct Edge var;
            cin >> var.v >> var.w;
            e[i].push_back(var);
        }    
    }

    for (int i = n-m+1; i <= n; i++)
        cin >> dp[i][1];

    init(1);
    dfs(1);

    for (int i = m; i >= 0; i--) {
        if (dp[1][i] >= 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}


#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

vector<int> e[100000];
long long dp[100000][2];
int color[100000];

void dfs(int u) {
    dp[u][1] = 0;
    dp[u][0] = 1;
    for (int v : e[u]) {
        dfs(v);
        dp[u][1] *= dp[v][0];
        dp[u][1] %= MOD;
        dp[u][1] += dp[u][0] * dp[v][1] % MOD;
        dp[u][1] %= MOD;
        dp[u][0] *= dp[v][0];
        dp[u][0] %= MOD;
    }

    if (color[u]) {
        dp[u][1] = dp[u][0];
    } else {
        dp[u][0] += dp[u][1];
        dp[u][0] %= MOD;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        e[u].push_back(i);
    }
    for (int i = 0; i < n; i++)
        cin >> color[i];

    dfs(0);
    cout << dp[0][1] << endl;

    return 0;
}


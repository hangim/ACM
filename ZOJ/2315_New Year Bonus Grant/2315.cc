#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> e[500001];
int dp[500001][2];
vector<int> rev;

void dfs(int u) {
    dp[u][0] = 1000;
    dp[u][1] = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i];
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += dp[v][1];
    }

    int tmp = 0;
    for (int i = 0; i < e[u].size(); i++) {
        int &v = e[u][i];
        tmp = max(tmp, dp[u][1] - dp[v][1] + dp[v][0]);
    }
    dp[u][1] = tmp;
}

void find(int u, int flag) {
    if (flag == 0) {
        rev.push_back(u);
        for (int i = 0; i < e[u].size(); i++) {
            int &v = e[u][i];
            find(v, 1);
        }
    } else {
        int index, tmp = INT_MIN;
        for (int i = 0; i < e[u].size(); i++) {
            int &v = e[u][i];
            if (dp[v][0] - dp[v][1] > tmp) {
                tmp = dp[v][0] - dp[v][1];
                index = v;
            }
        }
        for (int i = 0; i < e[u].size(); i++) {
            int &v = e[u][i];
            if (v == index)
                find(v, 0);
            else
                find(v, 1);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 2; i <= n; i++) {
            int u;
            cin >> u;
            e[u].push_back(i);
        }

        memset(dp, 0, sizeof(dp));
        rev.clear();

        dfs(1);
        cout << dp[1][1] << endl;

        find(1, 1);
        sort(rev.begin(), rev.end());
        for (int i = 0; i < rev.size(); i++) {
            cout << rev[i];
            if (i != rev.size() - 1)
                cout << " ";
            else
                cout << endl;
        }

        if (t)
            cout << endl;
    }

    return 0;
}


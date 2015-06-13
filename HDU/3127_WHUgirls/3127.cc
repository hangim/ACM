#include <bits/stdc++.h>

using namespace std;

int x[11], y[11], p[11];
int dp[1001][1001];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i != N; ++i)
            cin >> x[i] >> y[i] >> p[i];
        for (int i = 1; i <= X; ++i) {
            for (int j = 1; j <= Y; ++j) {
                for (int k = 0; k != N; ++k) {
                    if (i >= x[k] and j >= y[k]) {
                        dp[i][j] = max(dp[i][j], dp[i-x[k]][j] + p[k] + dp[x[k]][j-y[k]]);
                        dp[i][j] = max(dp[i][j], dp[i][j-y[k]] + p[k] + dp[i-x[k]][y[k]]);
                    }
                    if (i >= y[k] and j >= x[k]) {
                        dp[i][j] = max(dp[i][j], dp[i-y[k]][j] + p[k] + dp[y[k]][j-x[k]]);
                        dp[i][j] = max(dp[i][j], dp[i][j-x[k]] + p[k] + dp[i-y[k]][x[k]]);
                    }
                }
            }
        }
        cout << dp[X][Y] << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

double dp[2][5010][2];

int main() {
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        int n, s;
        scanf("%d %d", &n, &s);
        int n_yes = s - 2 * n;
        int n_no = n - n_yes;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n + 1; ++i) {
            for (int j = 0; j <= min(i, n_yes); ++j) {
                dp[i % 2][j][1] = 1.0 * (dp[(i + 1) % 2][j][0] + 1) * (i - j) / i;
                if (j > 0)
                    dp[i % 2][j][1] += 1.0 * dp[(i + 1) % 2][j-1][1] * j / i;

                dp[i % 2][j][0] = 1.0 * dp[(i + 1) % 2][j][0] * (i - j) / i;
                if (j > 0)
                    dp[i % 2][j][0] += 1.0 * (dp[(i + 1) % 2][j-1][1] + 1) * j / i;
            }
        }

        printf("Case %d: %.6lf\n", k,  dp[n % 2][n_yes][1]);
    }
    return 0;
}


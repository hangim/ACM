#include <bits/stdc++.h>

using namespace std;

double dp[100010];

int main() {
    dp[1] = 0;
    for (int i = 2; i <= 100000; ++i) {
        int cnt = 2;
        dp[i] = 0;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                dp[i] += dp[j] + dp[i / j];
                cnt += 2;
                if (j * j == i) {
                    dp[i] -= dp[j];
                    --cnt;
                }
            }
        }
        dp[i] = (dp[i] + cnt) / (cnt - 1);
    }

    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int d;
        cin >> d;
        cout << "Case " << k << ": "
             << setprecision(6) << fixed << dp[d] << endl;
    }
    return 0;
}


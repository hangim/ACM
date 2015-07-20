#include <bits/stdc++.h>

using namespace std;

double dp[110];

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> dp[i];
        for (int i = n - 1; i >= 1; --i) {
            for (int j = min(i + 6, n); j > i; --j)
                dp[i] += dp[j] / min(n - i, 6);
        }
        cout << setprecision(6) << fixed
             << "Case " << cases << ": " << dp[1] << endl;
    }
    return 0;
}


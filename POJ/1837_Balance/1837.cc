#include <iostream>

using namespace std;

int main() {
    int c, g;
    int x[21], w[21];
    cin >> c >> g;
    for (int i = 1; i <= c; i++)
        cin >> x[i];
    for (int i = 1; i <= g; i++)
        cin >> w[i];

    int dp[21][15001] = {0};
    dp[0][7500] = 1;
    for (int i = 1; i <= g; i++) {
        for (int j = 1; j <= c; j++) {
            int tmp = x[j] * w[i];
            for (int k = 0; k <= 15000; k++) {
                if (k - tmp < 0 or k - tmp > 15000)
                    continue;
                if (dp[i-1][k-tmp] > 0)
                    dp[i][k] += dp[i-1][k-tmp];
            }
        }
    }
    
    cout << dp[g][7500] << endl;

    return 0;
}


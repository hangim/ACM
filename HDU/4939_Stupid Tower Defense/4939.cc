#include <iostream>
#include <cstring>

using namespace std;

long long dp[1501][1501];

int main() {
    int t;
    cin >> t;
    int index = 1;
    while (t--) {
        long long n, x, y, z, t;
        cin >> n >> x >> y >> z >> t;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + (i-1) * y * t; // all green
            for (int j = 1; j < i; j++) {
                dp[i][j] = max(dp[i-1][j-1] + ((i-1)-(j-1)) * y * (t + (j-1)*z),
                               dp[i-1][j] + (i-1-j) * y * (t + j * z));
            }
            // dp[i][i] = 0; // all blue
        }

        long long ans = 0;
        for (int i = n; i >= 1; i--) {
            for (int j = i; j >= 0; j--)
                // n-i red
                // i-j green
                // j   blue
                ans = max(ans, dp[i][j] + (n-i) * (x + (i-j) * y) * (t + j * z));
        }
        ans = max(ans, n * x * t); // all red
        cout << "Case #" << index++ << ": " << ans << endl;
    }

    return 0;
}


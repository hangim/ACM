#include <iostream>
#include <cstring>

using namespace std;

char m[1001][1001];
int dp[1001][1001];

int main() {
    int n;
    while (cin >> n and n) {
        for (int i = 0; i != n; ++i)
            cin >> m[i];
        memset(dp, 0, sizeof(dp));

        int ans = 1;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != n; ++j) {
                if (i == 0 or j == n - 1) {
                    dp[i][j] = 1;
                    continue;
                }
                int k = 1;
                while (i - k >= 0 and j + k < n and m[i-k][j] == m[i][j+k])
                    ++k;
                if (k > dp[i-1][j+1])
                    dp[i][j] = dp[i-1][j+1] + 1;
                else
                    dp[i][j] = k;
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

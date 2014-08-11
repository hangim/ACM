#include <iostream>
#include <cstring>

using namespace std;

int dp[32][32];

void init() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 32; i++)
        dp[i][0] = 1;

    // dp[i][j] 长度为 i, 包含 j 个 0
    for (int i = 1; i < 32; i++) { // allow leading zero
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
}

int solve(int n) {
    int w[32];
    memset(w, 0, sizeof(w));

    int len = 0;
    while (n) {
        w[++len] = n % 2;
        n /= 2;
    }

    int ans = 0;
    // 统计长度比 N 小的, 令首位为 1
    for (int i = 1; i < len; i++) {
        for (int j = i - 1; 2 * j >= i; j--)
            ans += dp[i - 1][j];
    }

    // 统计长度和 N 相同,但是值比 N 小的
    for (int i = len - 1, zero = 0; i >= 1; i--) {
        if (w[i]) { // 如果某位为 1, 则置 0, 枚举低位
            zero++;
            for (int j = i - 1; 2 * (j + zero) >= len; j--) {
                ans += dp[i-1][j];
            }
            zero--;
        } else {
            zero++;
        }
    }

    return ans;
}

int main() {
    init();

    int start, finish;
    cin >> start >> finish;
    cout << solve(finish + 1) - solve(start) << endl;

    return 0;
}


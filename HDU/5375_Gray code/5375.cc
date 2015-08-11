#include <bits/stdc++.h>

using namespace std;

int a[200000 + 10];
char s[200000 + 10];
int dp[200000 + 10][2];
int n;

int solve() {
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i][1] = 0;
        if (s[n-i+1] == '0' or s[n-i+1] == '?')
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        if (s[n-i+1] == '1' or s[n-i+1] == '?') {
            if (s[n-i+1+1] == '1')
                dp[i][1] = a[i] + dp[i-1][1] - a[i-1];
            else
                dp[i][1] = a[i] + max(dp[i-1][0] + a[i-1], dp[i-1][1] - a[i-1]);
        }
        //printf("dp[%d][0] == %d, dp[%d][1] == %d\n", i, dp[i][0], i, dp[i][1]);
    }
    return max(dp[n][0], dp[n][1]);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        for (int i = n; i >= 1; --i)
            scanf("%d", &a[i]);
        printf("Case #%d: %d\n", cs, solve());
    }
}

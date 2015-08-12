#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
const int maxn = 50;
long long c[maxn + 10][maxn + 10];

void init_c() {
    for (int i = 0; i <= maxn; ++i)
        c[i][0] = 1;
    for (int i = 1; i <= maxn; ++i)
        for (int j = 1; j <= i; ++j)
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
}

long long dp[200 + 10][50 + 10];

void init_dp(int N, int K) {
    for (int i = 1; i <= N; ++i)
        dp[i][1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= K; j++)
            dp[i][j] = (j * dp[i-1][j-1] + j * dp[i-1][j]) % mod;
    }   
}

int main() {
    init_c();
    init_dp(200, 50);

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);

        if (n == 0 and m == 0) {
            printf("Case %d: %d\n", cs, k);
            continue;
        }

        int x = (n + 1) * (m + 1) / 2;
        int y = (n + 1) * (m + 1) - x;
        long long ans = 0;
        for (int i = 1; i < k; ++i) {
            for (int j = 1; i + j <= k; ++j)
                ans = (ans + c[k][i] * c[k-i][j] % mod * dp[x][i] % mod * dp[y][j] % mod) % mod;
        }
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


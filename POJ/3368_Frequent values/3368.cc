#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>

int n;
int num[100001];
int f[100001];
int dp[100001][17];

int max(int x, int y) {
    return x > y ? x : y;
}

void spare_table() {
    for (int i = 1; i <= n; i++)
        dp[i][0] = f[i];

    int k = log(n + 1) / log(2);
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i + (1<<j) -1 <= n; i++) {
            dp[i][j] = max(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
        }
    } 
}

int rmq(int x, int y) {
    if (x > y)
        return 0;

    int k = log(y - x + 1) / log(2);
    return max(dp[x][k], dp[y - (1<<k) + 1][k]);
}

int main() {
    while (scanf("%d", &n) and n) {
        int q;
        scanf("%d", &q);
        
        num[0] = INT_MIN;
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        f[0] = INT_MIN;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (num[i] == num[i-1])
                f[i] = f[i-1] + 1;
            else
                f[i] = 1;
        }

        spare_table();

        for (int i = 0; i < q; i++) {
            int x, y;
            scanf("%d%d", &x, &y);

            if (num[x] == num[y]) {
                printf("%d\n", y-x+1);
            } else {
                int t = x;
                while (t <= y and num[t] == num[t-1])
                    t++;

                printf("%d\n", max(t - x, rmq(t, y)));
            }
        }
    }

    return 0;
}


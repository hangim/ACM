#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int A[N];
long long pre[N], dp[N];

int main() {
    int n, m;
    while (scanf("%d %d", &m, &n) != -1) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &A[i]);
            dp[i] = pre[i] = 0;
        }
        dp[0] = pre[0] = 0;

        long long tmp;
        for (int i = 1; i <= m; ++i) {
            tmp = INT_MIN;
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j-1] + A[j], pre[j-1] + A[j]);
                pre[j-1] = tmp;
                tmp = max(tmp, dp[j]);
            }
        }
        
        printf("%lld\n", tmp);
    }

    return 0;
}


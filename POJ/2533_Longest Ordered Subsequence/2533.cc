#include <cstdio>
#include <algorithm>

using namespace std;

int A[1001];
int dp[1001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d", &A[i]);
        dp[i] = 1;
    }

    for (int i = 1; i != n; ++i) {
        for (int j = 0; j != i; ++j) {
            if (A[i] > A[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i != n; ++i)
        ans = max(ans, dp[i]);

    printf("%d\n", ans);

    return 0;
}


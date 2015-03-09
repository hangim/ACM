#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1001];
int V[1001], W[1001];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));

        int n, v;
        scanf("%d%d", &n, &v);
        for (int i = 0; i != n; ++i)
            scanf("%d", &W[i]);
        for (int i = 0; i != n; ++i)
            scanf("%d", &V[i]);

        for (int i = 0; i != n; ++i) {
            for (int j = v; j >= V[i]; --j)
                dp[j] = max(dp[j], dp[j-V[i]] + W[i]);
        }

        printf("%d\n", dp[v]);
    }

    return 0;
}

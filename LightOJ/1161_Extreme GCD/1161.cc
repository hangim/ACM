#include <bits/stdc++.h>

using namespace std;

long long C[10000 + 10];
int cnt[10000 + 10];
long long ans[10000 + 10];

int main() {
    C[4] = 1;
    for (int i = 5; i <= 10000; ++i)
        C[i] = C[i-1] * i / (i - 4);

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        int maxx = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            maxx = max(maxx, x);
            for (int j = 1; j * j <= x; j++)
                if (x % j == 0) {
                    cnt[j]++;
                    if (j * j != x)
                        cnt[x/j]++;
                }
        }

        memset(ans, 0, sizeof(ans));
        for (int i = maxx; i >= 1; i--) {
            ans[i] = C[cnt[i]];
            for (int j = i + i; j <= maxx; j += i)
                ans[i] -= ans[j];
        }

        printf("Case %d: %lld\n", cs, ans[1]);
    }
    return 0;
}


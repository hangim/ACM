#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000010;
unsigned vis[maxn / 32 + 10];
int pri[5761455 + 10], cnt = 0;

void init_pri() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not (vis[i / 32] & (1 << i % 32)))
            for (int j = i * i; j <= maxn; j += i)
                vis[j / 32] |= 1 << j % 32;
    for (int i = 2; i <= maxn; ++i)
        if (not (vis[i / 32] & (1 << i % 32)))
            pri[cnt++] = i;
}

unsigned data[5761455 + 10];

int main() {
    init_pri();

    data[0] = pri[0];
    for (int i = 1; i < cnt; ++i)
        data[i] = data[i-1] * pri[i];

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);

        unsigned int ans = 1;
        int pos = upper_bound(pri, pri + cnt, n) - pri;
        ans = data[pos - 1];

        for (int i = 0; i < cnt and pri[i] * pri[i] <= n; ++i) {
            int t = pri[i];
            while (t <= n / pri[i]) {
                ans *= pri[i];
                t *= pri[i];
            }
        }

        printf("Case %d: %u\n", cs, ans);

    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
unsigned vis[maxn / 32 + 10];
int pri[78498 + 10], cnt = 0;

void init_pri() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not (vis[i / 32] & (1 << i % 32)))
            for (int j = i * i; j <= maxn; j += i)
                vis[j / 32] |= 1 << j % 32;
    for (int i = 2; i <= maxn; ++i)
        if (not (vis[i / 32] & (1 << i % 32)))
            pri[cnt++] = i;
}

const long long mod = 1000000007;

long long pow_mod(long long x, long long n) {
    x %= mod;
    long long c = 1;
    while (n) {
        if (n & 1)
            c = c * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return c;
}

long long inv(long long x) {
    return pow_mod(x, mod - 2);
}

long long data[78498 + 10];

int main() {
    init_pri();

    data[0] = pri[0];
    for (int i = 1; i < cnt; ++i)
        data[i] = data[i-1] * pri[i] % mod;

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        n++;

        long long ans = 1;
        int pos = upper_bound(pri, pri + cnt, n) - pri;
        ans = data[pos - 1];

        for (int i = 0; i < cnt and pri[i] * pri[i] <= n; ++i) {
            int t = pri[i];
            while (t <= n / pri[i]) {
                ans = ans * pri[i] % mod;
                t *= pri[i];
            }
        }

        printf("%lld\n", ans * inv(n) % mod);
    }

    return 0;
}


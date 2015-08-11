#include <bits/stdc++.h>

const int maxn = 500000;
long long a[maxn + 10];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, m, z, l;
        scanf("%lld %lld %lld %lld", &n, &m, &z, &l);
        long long ans = 0;
        a[1] = 0;
        for (int i = 2; i <= n; ++i) {
            a[i] = (a[i-1] * m + z) % l;
            ans ^= 2 * a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}


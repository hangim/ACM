#include <bits/stdc++.h>

using namespace std;

void extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        extended_gcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

long long CRT(long long *a, long long *m, int n) {
    long long M = 1, x, y, ans = 0;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    for (int i = 0; i < n; ++i) {
        long long w = M / m[i];
        extended_gcd(w, m[i], x, y);
        ans = (ans + a[i] * w * x) % M;
    }
    return (ans + M) % M;
}

long long a[15], m[15];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
            scanf("%lld %lld", &m[i], &a[i]);

        printf("Case %d: %lld\n", cs, CRT(a, m, n));
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int bit_count(int x) {
    int c = 1;
    while (x) {
        c += x & 1;
        x >>= 1;
    }
    return c;
}

int a[20];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n;
        int m;
        scanf("%lld %d", &n, &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &a[i]);

        long long ans = 0;
        for (int i = 0; i < (1 << m); ++i) {
            long long lc = 1;
            for (int j = 0; j < m; ++j)
                if (i & (1 << j))
                    lc = lcm(lc, a[j]);
            if (bit_count(i) & 1)
                ans += n / lc;
            else
                ans -= n / lc;
        }

        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


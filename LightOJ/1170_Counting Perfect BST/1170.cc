#include <bits/stdc++.h>

using namespace std;

const long long mod = 100000007;

const int maxn = 2e5;;
long long fac[maxn + 10];

void init_fac() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fac[i] = fac[i-1] * i % mod;
}

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

long long C(long long n, long long m) {
    return n < m ? 0 : fac[n] * inv(fac[m]) % mod * inv(fac[n - m]) % mod;
}

long long Catalan(long long n) {
    return C(2 * n, n) * inv(n + 1) % mod;
}

long long a[(int)1.1e6 + 10];
int c = 0;

void init() {
    for (long long x = 2; x <= 1e5; ++x) {
        long long m = x * x;
        while (m <= 1e10) {
            a[c++] = m;
            m *= x;
        }
    }
    sort(a, a + c);
    c = unique(a, a + c) - a;
}

int main() {
    init_fac();
    init();

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long aa, bb;
        scanf("%lld %lld", &aa, &bb);
        int n = upper_bound(a, a + c, bb) - upper_bound(a, a + c, aa - 1);
        printf("Case %d: %lld\n", cs, n == 0 ? 0 : Catalan(n));
    }
    return 0;
}


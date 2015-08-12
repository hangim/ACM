#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
const int maxn = 1000;
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

int main() {
    init_fac();

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);

        long long ans = 0;
        for (long long i = 0; i <= m - k; i++)
            ans = (ans + C(m - k, i) * fac[n - k - i] * (i % 2 ? -1 : 1)) % mod;
        ans = (ans * C(m, k) % mod + mod) % mod;

        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

const int maxn = 1000;
long long inv[maxn + 10];
void init_inv() {
    inv[1] = 1;
    for (int i = 2; i <= maxn; ++i)
        inv[i] = ((-mod / i * inv[mod % i]) % mod + mod) % mod;
}

long long pow_mod(long long x, long long n) {
    x %= mod;
    n %= mod - 1;
    long long c = 1;
    while (n) {
        if (n & 1)
            c = c * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return c;
}

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long polya(long long n, long long k) {
    long long c = 0;
    for (int i = 0; i < n; ++i)
        c = (c + pow_mod(k, gcd(n, i))) % mod;
    return c * inv[n] % mod;
}

int main() {
    init_inv();

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        printf("Case %d: %lld\n", cs, polya(n, k));
    }
    return 0;
}


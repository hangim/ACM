#include <bits/stdc++.h>

using namespace std;

long long MOD;
 
long long pow_mod(long long x, long long n) {
    long long c = 1;
    while (n) {
        if (n & 1)
            c = c * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return c;
}

const int maxn = 100000;
long long fac[maxn + 10];
 
void init_fac() {
    fac[0] = 1;
    for (int i = 1; i <= MOD; ++i)
        fac[i] = fac[i-1] * i % MOD;
}

long long inv(long long x) {
    return pow_mod(x, MOD - 2);
}
 
long long C(long long n, long long m) {
    return n < m ? 0 : fac[n] * inv(fac[m]) % MOD * inv(fac[n - m]) % MOD;
}

long long Lucas(long long n, long long m) {
    long long ans = 1;
    while (n and m) {
        ans = ans * C(n % MOD, m % MOD) % MOD;
        n /= MOD;
        m /= MOD;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n, m;
        scanf("%lld %lld %lld", &n, &m, &MOD);
        init_fac();
        printf("%lld\n", Lucas(n + m, n));
    }
    return 0;
}


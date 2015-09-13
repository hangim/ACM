#include <bits/stdc++.h>

using namespace std;


const int maxn = 100000;
long long fac[maxn + 10];

void init_fac(long long mod) {
    fac[0] = 1;
    int t = min(maxn, (int)mod);
    for (int i = 1; i <= maxn; ++i)
        fac[i] = fac[i-1] * i % mod;
}

long long pow_mod(long long x, long long n, long long mod) {
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

long long inv(long long x, long long mod) {
    return pow_mod(x, mod - 2, mod);
}

long long C(long long n, long long m, long long mod) {
    return n < m ? 0 : fac[n] * inv(fac[m], mod) % mod * inv(fac[n - m], mod) % mod;
}

long long Lucas(long long n, long long m, long long mod) {
    long long ans = 1;
    while (n and m) {
        ans = ans * C(n % mod, m % mod, mod) % mod;
        n /= mod;
        m /= mod;
    }
    return ans;
}


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
        ans = (ans + (__int128)a[i] * w * x % M) % M;
    }
    return (ans + M) % M;
}


long long p[30];
long long a[30];

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        int k;
        cin >> n >> m >> k;
        for (int i = 0; i < k; ++i) {
            cin >> p[i];
            init_fac(p[i]);
            a[i] = Lucas(n, m, p[i]);
        }
        long long ans = CRT(a, p, k);
        cout << ans << endl;
    }

    return 0;
}


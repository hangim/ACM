#include <bits/stdc++.h>

using namespace std;

long long MOD;

long long pow_mod(long long a, long long b) {
    long long c = 1;
    a %= MOD;
    while (b) {
        if (b & 1)
            c = c * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return c;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, k, sum = 0, t;
        scanf("%lld %lld %lld", &n, &k, &MOD);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &t);
            sum = (sum + t) % MOD;
        }
        printf("Case %d: %lld\n", cs, (k % MOD) * pow_mod(n, k - 1) * sum % MOD);
    }
    return 0;
}


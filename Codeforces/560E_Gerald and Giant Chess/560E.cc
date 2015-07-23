#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;

const int MAXN = 200000 + 10;
long long fac[MAXN], inv[MAXN], dp[2010];

struct Point {
    long long x, y;
} p[2010];

bool cmp(Point a, Point b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

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

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = pow_mod(fac[i], MOD - 2);
    }
}

long long C(long long m, long long n) {
    return ((fac[m] * inv[n]) % MOD) * inv[m - n] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    long long h, w, n;
    cin >> h >> w >> n;

    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    sort(p, p + n, cmp);

    p[n].x = h, p[n].y = w;
    for (int i = 0; i <= n; ++i) {
        dp[i] = C(p[i].x + p[i].y - 2, p[i].x - 1);
        for (int j = 0; j < i; ++j)
            if (p[j].x <= p[i].x and p[j].y <= p[i].y)
                dp[i] = ((dp[i] - dp[j] * C(p[i].x - p[j].x + p[i].y - p[j].y, p[i].x - p[j].x)) % MOD + MOD) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const long long mod = 10000007;

void matrix_multi(long long a[12][12], long long b[12][12]) {
    long long c[12][12] = {0};
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 12; ++j)
            for (int k = 0; k < 12; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    memcpy(a, c, sizeof(c));
}

void matrix_pow(long long m[12][12], long long n) {
    long long c[12][12] = {0};
    for (int i = 0; i < 12; ++i)
        c[i][i] = 1;

    while (n) {
        if (n & 1)
            matrix_multi(c, m);
        matrix_multi(m, m);
        n >>= 1;
    }
    memcpy(m, c, sizeof(c));
}

int main() {
    long long n, m;
    while (cin >> n >> m) {
        long long b[12][12] = {0};
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j <= i; ++j)
                b[i][j] = 1;
        for (int i = 1; i < 12; ++i)
            b[i][1] = 10;
        matrix_pow(b, m);

        long long ans = (3 * b[n+1][0] + 23 * b[n+1][1]) % mod;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            ans = (ans + a * b[n+1][2+i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}


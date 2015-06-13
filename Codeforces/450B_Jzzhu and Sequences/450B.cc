#include <bits/stdc++.h>

using namespace std;

long long mod = 1000000007;

void matrix_multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    memcpy(a, c, sizeof(c));
}

void matrix_quick_pow(long long m[2][2], long long n) {
    long long c[2][2] = {1, 0, 0, 1};
    while (n) {
        if (n & 1)
            matrix_multi(c, m);
        matrix_multi(m, m);
        n >>= 1;
    }
    memcpy(m, c, sizeof(c));
}

int main() {
    long long x, y, n;
    cin >> x >> y >> n;
    x = (x % mod + mod) % mod;
    y = (y % mod + mod) % mod;
    if (n == 1) {
        cout << x << endl;
        return 0;
    }
    if (n == 2) {
        cout << y << endl;
        return 0;
    }

    long long m[2][2] = {1, 1, -1, 0};
    matrix_quick_pow(m, n-2);
    cout << (((y * m[0][0] + x * m[1][0]) % mod) + mod) % mod << endl;

    return 0;
}


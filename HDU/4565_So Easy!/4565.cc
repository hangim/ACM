#include <bits/stdc++.h>

using namespace std;
long long mod;

void mat_multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = ((c[i][j] + a[i][k] * b[k][j]) % mod + mod) % mod;
    memcpy(a, c, sizeof(c));
}

void mat_pow(long long a[2][2], long long n) {
    long long c[2][2] = {1, 0, 0, 1};
    while (n) {
        if (n & 1)
            mat_multi(c, a);
        mat_multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    long long a, b, n;
    while (cin >> a >> b >> n >> mod) {
        long long s0 = 2, s1 = 2 * a;
        if (n == 1) {
            cout << s1 % mod << endl;
            continue;
        }

        long long c[2][2] = {2 * a, 1, b - a * a, 0};
        mat_pow(c, n - 1);
        cout << ((s1 * c[0][0] + s0 * c[1][0]) % mod + mod) % mod<< endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const long long mod = 100000;
long long modm[5] = {1, 10, 100, 1000, 10000};

void matrix_multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    memcpy(a, c, sizeof(c));
}

void matrix_pow(long long a[2][2], long long n) {
    long long c[2][2] = {1, 0, 0, 1};
    while (n) {
        if (n & 1)
            matrix_multi(c, a);
        matrix_multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        if (n == 0) {
            cout << a % modm[m] << endl;
            continue;
        }
        if (n == 1) {
            cout << b % modm[m] << endl;
            continue;
        }
        long long mat[2][2] = {1, 1, 1, 0};
        matrix_pow(mat, n - 1);
        cout << (b * mat[0][0] + a * mat[1][0]) % modm[m] << endl;
    }
    return 0;
}


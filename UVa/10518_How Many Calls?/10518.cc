#include <bits/stdc++.h>

using namespace std;

long long mod;

void matrix_multi(long long a[3][3], long long b[3][3]) {
    long long c[3][3] = {0};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    memcpy(a, c, sizeof(c));
}

void matrix_pow(long long a[3][3], long long n) {
    long long c[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    while (n) {
        if (n & 1)
            matrix_multi(c, a);
        matrix_multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    long long n;
    long long k = 1;
    while (cin >> n >> mod and n + mod) {
        cout << "Case " << k++ << ": " << n << " " << mod << " ";
        if (n == 0 or n == 1) {
            cout << 1 % mod << endl;
            continue;
        }
        long long mat[3][3] = {1, 1, 0, 1, 0, 0, 1, 0, 1};
        matrix_pow(mat, n - 1);
        cout << (mat[0][0] + mat[1][0] + mat[2][0]) % mod << endl;
    }
    return 0;
}


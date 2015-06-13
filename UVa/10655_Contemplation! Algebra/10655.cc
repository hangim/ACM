#include <bits/stdc++.h>

using namespace std;

void multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] += a[i][k] * b[k][j];
    memcpy(a, c, sizeof(c));
}

void pow(long long a[2][2], long long n) {
    long long c[2][2] = {1, 0, 0, 1};
    while (n) {
        if (n & 1)
            multi(c, a);
        multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    long long p, q, n;
    while (cin >> p >> q >> n) {
        long long f0 = 2, f1 = p;
        if (n == 0) {
            cout << f0 << endl;
            continue;
        }
        long long m[2][2] = {p, 1, -q, 0};
        pow(m, n - 1);
        cout << f1 * m[0][0] + f0 * m[1][0] << endl;
    }
    return 0;
}


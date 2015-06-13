#include <bits/stdc++.h>

using namespace std;

void mat_multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 1000000006;
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

long long quick_pow(long long a, long long n) {
    long long c = 1;
    while (n) {
        if (n & 1)
            c = (c * a) % 1000000007;
        a = a * a % 1000000007;
        n >>= 1;
    }
    return c;
}

int main() {
    long long a, b, n;
    while (cin >> a >> b >> n) {
        long long fib[2][2] = {1, 1, 1, 0};
        if (n == 0) {
            cout << a << endl;
            continue;
        } else if (n == 1) {
            cout << b << endl;
            continue;
        }
        mat_pow(fib, n - 1);
        cout << quick_pow(b, fib[0][0]) * quick_pow(a, fib[0][1])
            % 1000000007 << endl;
    }
    return 0;
}


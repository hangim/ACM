#include <iostream>
#include <cstring>

using namespace std;

long long mod;

void multi(long long a[2][2], long long b[2][2]) {
    long long c[2][2] = {0};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
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

long long fib(long long n) {
    if (n == 0)
        return 0;
    if (n == 1 or n == 2)
        return 1;
    long long a[2][2] = {1, 1, 1, 0};
    pow(a, n - 1);
    return a[0][0];
}

int main() {
    int T;
    cin >> T;
    int k = 1;
    while (T--) {
        long long n;
        cin >> n >> mod;
        cout << "Case " << k++ << ": ";
        long long s = (fib(n + 2) - 1 + mod) % mod;
        if (s == 0 or s % 2) {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
        for (int i = 1; i <= s; ++i) {
            for (int j = 1; j <= s; ++j) {
                if (j < i)
                    cout << 1;
                else if (j == i)
                    cout << i % 2;
                else
                    cout << -1;

                if (j == s)
                    cout << endl;
                else
                    cout << " ";
            }
        }
    }
    return 0;
}


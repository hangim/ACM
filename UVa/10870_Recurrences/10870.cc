#include <bits/stdc++.h>

using namespace std;

int d, n, m;

void multi(int a[15][15], int b[15][15]) {
    int c[15][15] = {0};
    for (int i = 0; i < d; ++i)
        for (int j = 0; j < d; ++j)
            for (int k = 0; k < d; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m;
    memcpy(a, c, sizeof(c));
}

void pow(int a[15][15], int n) {
    int c[15][15] = {0};
    for (int i = 0; i < d; ++i)
        c[i][i] = 1;
    while (n) {
        if (n & 1)
            multi(c, a);
        multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    while (cin >> d >> n >> m and d + n + m) {
        int mat[15][15] = {0};
        for (int i = 0; i < d; ++i) {
            cin >> mat[i][0];
            mat[i][0] %= m;
        }
        for (int i = 1; i < d; ++i)
            mat[i-1][i] = 1;

        int F[15];
        for (int i = 0; i < d; ++i) {
            cin >> F[i];
            F[i] %= m;
        }

        pow(mat, n - d);
        int ans = 0;
        for (int i = 0; i < d; ++i)
            ans = (ans + mat[i][0] * F[d-1-i]) % m;
        cout << ans << endl;
    }
    return 0;
}


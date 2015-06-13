#include <iostream>
#include <cstring>

using namespace std;

#define LL long long

const LL MOD = 1000000007;

void mat_multi(LL a[5][5], LL b[5][5]) {
    LL c[5][5] = {0};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    memcpy(a, c, sizeof(c));
}

void mat_pow(LL a[5][5], LL n) {
    LL c[5][5] = {0};
    for (int i = 0; i < 5; ++i)
        c[i][i] = 1;
    while (n) {
        if (n & 1)
            mat_multi(c, a);
        mat_multi(a, a);
        n >>= 1;
    }
    memcpy(a, c, sizeof(c));
}

int main() {
    LL N, A0, AX, AY, B0, BX, BY;
    while (cin >> N >> A0 >> AX >> AY >> B0 >> BX >> BY) {
        if (N == 0) {
            cout << 0 << endl;
            continue;
        }

        LL m[5][5] = {
            1,       0,  0,  0, 0,
            1, AX * BX,  0,  0, 0,
            0, AX * BY, AX,  0, 0,
            0, BX * AY,  0, BX, 0,
            0, AY * BY, AY, BY, 1,
        };
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                m[i][j] %= MOD;
        mat_pow(m, N);

        cout << ((A0 * B0 % MOD) * m[1][0] + (A0 % MOD) * m[2][0]
            + (B0 % MOD) * m[3][0] + 1 * m[4][0]) % MOD << endl;
    }
    return 0;
}


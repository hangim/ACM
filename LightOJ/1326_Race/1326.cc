#include <bits/stdc++.h>

using namespace std;


long long mod = 10056;

const int maxn = 1000;
long long fac[maxn + 10];

void init_fac() {
    fac[0] = 1;
    for (int i = 1; i <= maxn; ++i)
        fac[i] = fac[i-1] * i % mod;
}

long long stir2[maxn + 10][maxn + 10];

void init_stir2() {
    stir2[1][1] = 1;
    for (int i = 2; i <= maxn; ++i)
        for (int j = 1; j <= i; ++j)
            stir2[i][j] = (stir2[i-1][j-1] + j * stir2[i-1][j]) % mod;
}

int main() {
    init_fac();
    init_stir2();

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n;
        scanf("%lld", &n);
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
            ans = (ans + fac[i] * stir2[n][i]) % mod;
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


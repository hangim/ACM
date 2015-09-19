#include <bits/stdc++.h>

using namespace std;

const long long mod = 530600414LL; // this maybe a QQ number :)
const int N = 201314;

long long F[N + 10], G[N + 10], pre[N + 10], last[N + 10], len[N + 10];

int main() {
    len[1] = 1, len[2] = 2;
    for (int i = 3; i <= N; ++i)
        len[i] = (len[i-1] + len[i-2]) % mod;

    G[3] = 1;
    for (int i = 4; i <= N; ++i)
        G[i] = (G[i-1] + G[i-2]) % mod;

    pre[4] = 2; // !!!
    for (int i = 5; i <= N; ++i)
        pre[i] = (pre[i-2] + pre[i-1] + len[i-2] * G[i-1] % mod) % mod;

    last[3] = 3, last[4] = 3; // !!!
    for (int i = 5; i <= N; ++i)
        last[i] = (last[i-1] + last[i-2] + len[i-1] * G[i-2] % mod) % mod;

    F[5] = 5;
    for (int i = 6; i <= N; ++i) {
        F[i] = ((((F[i-1] + F[i-2]) % mod) + last[i-2] * G[i-1] % mod) % mod + G[i-2] * pre[i-1] % mod) % mod;
    }

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %lld\n", cs, F[n]);
    }

    return 0;
}


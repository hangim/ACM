#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long W;
        scanf("%lld", &W);
        printf("Case %d: ", cs);
        if (W % 2) {
            puts("Impossible");
            continue;
        }

        long long N = W, M;
        while (N % 2 == 0)
            N /= 2;
        M = W / N;

        if (M + N == 0)
            puts("Impossible");
        else
            printf("%lld %lld\n", N, M);
    }
    return 0;
}


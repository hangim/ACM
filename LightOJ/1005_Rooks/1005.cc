#include <bits/stdc++.h>

using namespace std;

long long A(int n, int m) {
    long long c = 1;
    for (int i = 0; i < m; ++i)
        c *= n - i;
    return c;
}

long long C(int n, int m) {
    long long c = 1;
    for (int i = 0; i < m; ++i)
        c *= n - i;
    for (int i = 2; i <= m; ++i)
        c /= i;
    return c;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, k, ans = 1;
        scanf("%lld %lld", &n, &k);

        if (k > n)
            ans = 0;
        else
            ans = A(n, k) * C(n, k);

        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
int a[1010], b[1010], n;

long long solve() {
    long long ans = 1;
    for (int i = n - 1; i >= 0; --i) {
        int t = b + n - lower_bound(b, b + n, a[i]);
        if (t < n - i)
            return 0;
        ans = ans * (t - (n - i - 1)) % mod;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + n);

        printf("Case %d: %lld\n", cs, solve());
    }
    return 0;
}


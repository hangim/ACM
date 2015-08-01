#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        int s = sqrt(n);
        for (int i = 1; i <= s; ++i) {
            ans += (n / i - n / (i + 1)) * i;
            ans += n / i;
        }
        if (n / s == s)
            ans -= s;
        printf("Case %d: %lld\n", cs, ans);
    }

    return 0;
}


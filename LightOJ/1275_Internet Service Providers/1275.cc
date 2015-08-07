#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, c, t;
        scanf("%lld %lld", &n, &c);
        if (n != 0) {
            t = floor(0.5 * c / n);
            if ((t + 1) * (c - (t + 1) * n) > t * (c - t * n))
                ++t;
        } else {
            t = 0;
        }
        printf("Case %d: %lld\n", cs, t);
    }
    return 0;
}


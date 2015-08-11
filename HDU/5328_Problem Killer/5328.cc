#include <bits/stdc++.h>

using namespace std;

long long a[1000000 + 10];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
        }
        int ans = min(2,n);
        int aa = 0, bb = 0;
        for (int i = 3; i <= n; ++i) {
            if (2 * a[i-1] == a[i] + a[i-2]) {
                if (aa == 0)
                    aa = 3;
                else
                    ++aa;
            } else {
                aa = 0;
            }
            if (a[i-1] * a[i-1] == a[i] * a[i-2]) {
                if (bb == 0)
                    bb = 3;
                else
                    ++bb;
            } else {
                bb = 0;
            }
            ans = max(ans, max(aa, bb));
        }
        printf("%d\n", ans);
    }
    return 0;
}


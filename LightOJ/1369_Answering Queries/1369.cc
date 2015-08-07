#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
long long a[maxn + 10];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case %d:\n", cs);
        
        int n, q;
        scanf("%d %d", &n, &q);
 
        long long sum = 0;
        for (int i = 0, j = n - 1; i < n; ++i, j -= 2) {
            scanf("%lld", &a[i]);
            sum += j * a[i];
        }

        while (q--) {
            int cmd, x;
            long long v;
            scanf("%d", &cmd);
            if (cmd == 0) {
                scanf("%d %lld", &x, &v);
                sum += (n - 2 * x - 1) * (v - a[x]);
                a[x] = v;
            } else {
                printf("%lld\n", sum);
            }
        }
    }

    return 0;
}


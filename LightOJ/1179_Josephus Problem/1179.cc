#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n, k;
        scanf("%d %d", &n, &k);
        int ans = 0;
        for (int i = 2; i <= n; ++i)
            ans = (ans + k) % i;
        printf("Case %d: %d\n", cs, ans + 1);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

double H[1000000+10];

int main() {
    for (int i = 1, k = 1; k <= 1e6; ++k) {
        H[k] = H[k-1];
        for (int j = 0; j < 100; ++j)
            H[k] += 1.0 / i++;
    }

    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n;
        scanf("%d", &n);
        double ans = H[n/100];
        for (int i = n; i % 100; --i)
            ans += 1.0 / i;
        printf("Case %d: %.9f\n", cs, ans);
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m > n)
            swap(m, n);
        printf("Case %d: ", cs);
        if (m == 1) {
            printf("%d\n", n);
        } else if (m == 2) {
            printf("%d\n", n / 4 * 4 + min(n % 4 * 2, 4));
        } else {
            printf("%d\n", (n * m + 1) / 2);
        }
    }
    return 0;
}


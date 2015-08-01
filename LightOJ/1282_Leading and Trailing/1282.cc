#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        int n, k;
        scanf("%d %d", &n, &k);

        double e = k * log10(n);
        e -= floor(e);
        int head = pow(10.0, 2 + e);

        int tail = 1;
        int tk = k, tn = n % 1000;
        while (tk) {
            if (tk & 1)
                tail = tail * tn % 1000;
            tn = tn * tn % 1000;
            tk /= 2;
        }

        printf("Case %d: %3d %03d\n", cs, head, tail);
    }

    return 0;
}


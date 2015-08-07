#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        double l, w;
        scanf("%lf %lf", &l, &w);
        double x = (4 * (w + l) - sqrt(pow(4 * (w + l), 2) - 48 * w * l)) / 24;
        printf("Case %d: %.7f\n", cs, (w - 2 * x) * (l - 2 * x) * x);
    }
    return 0;
}


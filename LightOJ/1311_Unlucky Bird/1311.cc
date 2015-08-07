#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        double v1, v2, v3, a1, a2;
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        printf("Case %d: %.7f %.7f\n", cs,
                v1 * v1 / 2 / a1 + v2 * v2 / 2 / a2,
                max(v1 / a1, v2 / a2) * v3);
    }
    return 0;
}


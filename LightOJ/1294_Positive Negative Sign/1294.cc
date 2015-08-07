#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        printf("Case %d: %lld\n", cs, n * m / 2);
    }
    return 0;
}


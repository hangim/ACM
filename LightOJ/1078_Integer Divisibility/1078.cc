#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        int cnt = 1;
        long long tmp = m;
        while (tmp % n) {
            tmp = (tmp * 10 + m) % n;
            cnt++;
        }
        printf("Case %d: %d\n", cs, cnt);
    }
    return 0;
}


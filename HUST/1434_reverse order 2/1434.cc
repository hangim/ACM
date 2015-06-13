#include <bits/stdc++.h>

using namespace std;

int has[100010];

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        memset(has, 0, sizeof(has));
        long long bk = 0, b;
        for (long long i = 1; i < n; ++i) {
            scanf("%lld", &b);
            long long a = b - bk + i;
            printf("%lld ", a);
            has[a] = 1;
            bk = b;
        }
        for (int i = 1; i <= n; ++i) {
            if (has[i] == 0) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}


#include <cstdio>

const int maxn = (int)1e6;
int phi[maxn + 10];
long long cnt[maxn + 10];
 
void init_phi() {
    phi[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (not phi[i]) {
            for (int j = i; j <= maxn; j += i) {
                if (not phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    cnt[1] = 0;
    for (int i = 2; i <= maxn; ++i)
        cnt[i] = cnt[i-1] + phi[i];
}

int main() {
    init_phi();
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        printf("%lld\n", cnt[n]);
    }
    return 0;
}


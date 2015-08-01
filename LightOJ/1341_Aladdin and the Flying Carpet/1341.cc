#include <bits/stdc++.h>

using namespace std;

bool p[1000000+10];
int prime[1000000+10];
int cnt = 0;

void get_prime() {
    for (int i = 2; i * i <= 1e6; ++i)
        if (not p[i]) {
            for (int j = i * i; j <= 1e6; j += i)
                p[j] = true;
        }
    for (int i = 2; i <= 1e6; ++i)
        if (not p[i])
            prime[cnt++] = i;
}

long long slove(long long a, long long b) {
    if (b * b > a)
        return 0;

    long long ans = 1, tmp = a;
    for (int i = 0; i < cnt and prime[i] * prime[i] <= tmp; ++i) {
        int c = 0;
        while (tmp % prime[i] == 0) {
            ++c;
            tmp /= prime[i];
        }
        ans *= 1 + c;
    }
    if (tmp > 1)
        ans *= 2;
    ans /= 2;

    for (long long i = 1; i < b and i * i <= a; ++i) {
        if (a % i == 0)
            --ans;
    }
    return ans;
}

int main() {
    get_prime();
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("Case %d: %lld\n", k, slove(a, b));
    }
    return 0;
}


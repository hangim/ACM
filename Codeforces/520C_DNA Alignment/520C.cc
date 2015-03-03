#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long quickpow(long long m, long long n) {
    long long ans = 1;
    while (n) {
        if (n & 1)
            ans = ans * m % MOD;
        n = n >> 1;
        m = m * m % MOD;
    }
    return ans;
}

int main() {
    int n;
    char dna[100001];

    scanf("%d %s", &n, dna);
    
    int A, C, G, T;
    A = C = G = T = 0;
    for (int i = 0; i != n; ++i) {
        switch (dna[i]) {
        case 'A':
            ++A;
            break;

        case 'C':
            ++C;
            break;

        case 'G':
            ++G;
            break;

        case 'T':
            ++T;
            break;
        }
    }

    int maxn = max(max(A, C), max(G, T));
    int k = 0;
    if (A == maxn)
        ++k;
    if (C == maxn)
        ++k;
    if (G == maxn)
        ++k;
    if (T == maxn)
        ++k;

    printf("%lld\n", quickpow(k, n));

    return 0;
}


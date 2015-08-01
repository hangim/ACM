#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000001 + 10;

int phi[maxn];

void init_phi() {
    phi[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (not phi[i]) {
            for (int j = i; j < maxn; j += i) {
                if (not phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

long long ans[maxn];

int main() {
    init_phi();
    for (int i = 2; i < maxn; ++i)
        for (int j = 1; i * j < maxn; ++j)
            ans[i*j] += phi[i] * j;
    for (int i = 2; i < maxn; ++i)
        ans[i] += ans[i-1];

    int n;
    while (cin >> n and n)
        cout << ans[n] << endl;
    return 0;
}


#include <iostream>

using namespace std;

int n, m;
int l, r;
const long long MOD = 1000000009;

long long f[100001];

void input() {
    // 维护区间
    l = r = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int l1, r1;
        if (l >= x)
            l1 = l - x;
        else if (x <= r)
            l1 = (x - l) % 2 == 0 ? 0 : 1;
        else
            l1 = x - r;

        if (r + x <= m)
            r1 = r + x;
        else if (x <= m - l)
            r1 = (x - (m - r)) % 2 == 0 ? m : m - 1;
        else
            r1 = 2 * m - l - x;

        l = l1;
        r = r1;
    }
}

long long pow_mod(long long x, int e) {
    long long ans = 1;
    while (e) {
        if (e & 1)
            ans = ans * x % MOD;
        e >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

long long C(int m, int n) {
    return (f[m] * pow_mod(f[n], MOD-2) % MOD) * pow_mod(f[m-n], MOD-2) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    // 阶乘
    f[0] = 1;
    for (int i = 1; i <= 100000; i++)
        f[i] = f[i-1] * i % MOD;

    while (cin >> n >> m) {
        input();

        long long ans = 0;
        for (int i = l; i <= r; i += 2)
            ans = (ans + C(m, i)) % MOD;
        cout << ans << endl;;
    }

    return 0;
}


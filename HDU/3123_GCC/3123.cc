#include <bits/stdc++.h>

using namespace std;

long long f[1000010];

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        long long m;
        cin >> m;
        long long n = 0;
        for (int i = 0; i < str.length(); ++i) {
            n = n * 10 + str[i] - '0';
            if (n >= m) {
                n = m;
                break;
            }
        }
        f[0] = 1 % m;
        long long ans = 1 % m;
        for (long long i = 1; i <= n; ++i) {
            f[i] = f[i-1] * i % m;
            ans = (ans + f[i]) % m;
        }
        cout << ans << endl;
    }
    return 0;
}


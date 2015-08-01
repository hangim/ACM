#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 10;

bool prime[MAXN];
int phi[MAXN];

int table[MAXN];

int main() {
    // Eratosthenes
    for (int i = 1; i < MAXN; ++i)
        prime[i] = true, phi[i] = i;
    prime[1] = 0;
    for (int i = 2; i * i < MAXN; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN; j += i)
                prime[j] = false;
        }
    }

    // Euler's totient function
    for (int i = 2; i < MAXN; ++i) {
        if (prime[i]) {
            for (int j = i; j < MAXN; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
    
    for (int i = 2; i < MAXN; ++i) {
        if (table[phi[i]] == 0)
            table[phi[i]] = i;
    }
    int tmp = 1000003;
    for (int i = 1000002; i > 0; --i) {
        if (table[i])
            tmp = min(table[i], tmp);
        table[i] = tmp;
    }

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ans += table[x];
        }
        cout << "Case " << cases << ": " << ans << " Xukha" << endl;
    }

    return 0;
}


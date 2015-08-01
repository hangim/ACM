#include <bits/stdc++.h>

using namespace std;

int num[110];

int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
}

int main() {
    int T;
    cin >> T;
    cin.get();

    while (T--) {
        string s;
        getline(cin, s);
        istringstream is(s);

        int cnt = 0;
        while (is >> num[cnt])
            ++cnt;

        int ans = 0;
        for (int i = 0; i < cnt; ++i)
            for (int j = i + 1; j < cnt; ++j)
                ans = max(ans, gcd(num[i], num[j]));
        cout << ans << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        long long s, m, n, a, b;
        cin >> s;
        m = sqrt(s);
        n = m * m;
        cout << "Case " << cs << ": ";
        if (s == n)
            a = 1, b = m;
        else
            a = min(s - n, m + 1), b = min(2 * m + 2 - s + n, m + 1);
        if (m % 2)
            cout << a << " " << b << endl;
        else
            cout << b << " " << a << endl;
    }
    return 0;
}


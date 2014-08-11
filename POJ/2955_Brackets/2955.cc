#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int m[101][101];

int dp(int l, int r) {
    if (l >= r)
        return 0;
    if (m[l][r] != -1)
        return m[l][r];

    m[l][r] = dp(l + 1, r);
    if (s[l] == '(' or s[l] == '[') {
        for (int k = l; k <= r; k++) {
            if (s[l] == '(' and s[k] == ')' or s[l] == '[' and s[k] == ']')
                m[l][r] = max(m[l][r], dp(l + 1, k - 1) + 2 + dp(k + 1, r));
        }
    }

    return m[l][r];
}

int main() {
    while (cin >> s and s != "end") {
        memset(m, -1, sizeof(m));
        cout << dp(0, s.length() -  1) << endl;
    }

    return 0;
}


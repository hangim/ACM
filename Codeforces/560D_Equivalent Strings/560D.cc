#include <bits/stdc++.h>

using namespace std;

char a[200010], b[200010];

bool f(char *a, char *b, int n) {
    bool flag = true;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) {
            flag = false;
            break;
        }
    if (flag)
        return true;
    if (n % 2 == 0 and f(a, b + n / 2, n / 2) and f(a + n / 2, b, n / 2))
        return true;
    if (n % 2 == 0 and f(a, b, n / 2) and f(a + n / 2, b + n / 2, n / 2))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    if (f(a, b, strlen(a)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


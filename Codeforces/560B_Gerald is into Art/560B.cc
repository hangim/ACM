#include <bits/stdc++.h>

using namespace std;

int a1, b1;

bool f(int a2, int b2, int a3, int b3) {
    if ((a2 + a3 <= a1 and max(b2, b3) <= b1) or (max(a2, a3) <= a1 and b2 + b3 <= b1))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a2, b2, a3, b3;

    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    if (f(a2, b2, a3, b3) or f(b2, a2, a3, b3) or f(a2, b2, b3, a3) or f(b2, a2, b3, a3))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int f(int &a, int mod, int &cnt) {
    while (a % mod == 0) {
        a /= mod;
        ++cnt;
    }
}

int main() {
    int a1, b1, a2, b2;

    cin >> a1 >> b1 >> a2 >> b2;

    int x1 = a1, y1 = b1, x2 = a2, y2 = b2;
    int cnt12 = 0, cnt13 = 0, cnt22 = 0, cnt23 = 0;

    f(x1, 2, cnt12);
    f(x1, 3, cnt13);
    f(y1, 2, cnt12);
    f(y1, 3, cnt13);

    f(x2, 2, cnt22);
    f(x2, 3, cnt23);
    f(y2, 2, cnt22);
    f(y2, 3, cnt23);

    if (x1 * y1 != x2 * y2) {
        cout << -1 << endl;
        return 0;
    }
    
    int t = 0;
    while (cnt13 > cnt23) {
        ++t;
        --cnt13;
        ++cnt12;
        if (a1 % 3 == 0)
            a1 = a1 / 3 * 2;
        else
            b1 = b1 / 3 * 2;
    }
    while (cnt13 < cnt23) {
        ++t;
        --cnt23;
        ++cnt22;
        if (a2 % 3 == 0)
            a2 = a2 / 3 * 2;
        else
            b2 = b2 / 3 * 2;

    }
    while (cnt12 > cnt22) {
        ++t;
        --cnt12;
        if (a1 % 2 == 0)
            a1 /= 2;
        else
            b1 /= 2;
    }
    while (cnt12 < cnt22) {
        ++t;
        --cnt22;
        if (a2 % 2 == 0)
            a2 /= 2;
        else
            b2 /= 2;    
    }

    cout << t << endl;
    cout << a1 << " " << b1 << endl;
    cout << a2 << " " << b2 << endl;

    return 0;
}


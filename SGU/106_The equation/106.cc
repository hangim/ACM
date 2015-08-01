#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        extended_gcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

void calc(long long x1, long long x2, long long x, long long b, long long &lx, long long &rx) {
    if (b > 0) {
        x1 -= x;
        x2 -= x;
    } else {
        swap(x1, x2);
        x1 = x - x1;
        x2 = x - x2;
        b = -b;
    }
    lx = ceil(1.0 * x1 / b - 1e-8);
    rx = floor(1.0 * x2 / b + 1e-8);
    if (lx > rx)
        swap(lx, rx);
}

int main() {
    long long a, b, c, x1, x2, y1, y2, x, y, d;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    c = -c;

    if (a == 0 and b == 0) {
        if (c == 0)
            cout << (x2 - x1 + 1) * (y2 - y1 + 1) << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (a == 0) {
        if (c % b)
            cout << 0 << endl;
        else if (y1 <= c / b and c / b <= y2)
            cout << x2 - x1 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (b == 0) {
        if (c % a)
            cout << 0 << endl;
        else if (x1 <= c / a and c / a <= x2)
            cout << y2 - y1 + 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    
    d = gcd(a, b);
    extended_gcd(a, b, x, y);
    if (c % d) {
        cout << 0 << endl;
    } else {
        x *= c / d;
        y *= c / d;
        a /= d;
        b /= d;

        long long lx, rx, ly, ry;
        calc(x1, x2, x, b, lx, rx);
        calc(y1, y2, y, -a, ly, ry);

        cout << min(rx, ry) - max(lx, ly) + 1 << endl;
    }
    return 0;
}


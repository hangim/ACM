#include <iostream>

using namespace std;

// a * x + b * y = d
void extended_gcd(long long a, long long &x, long long b, long long &y, long long &d) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
    } else {
        extended_gcd(b, y, a % b, x, d);
        y -= a / b * x;
    }
}

int main() {
    long long x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;

    // (n - m) * p + l * q = x - y
    long long p, q, d;
    extended_gcd(n-m, p, l, q, d);
    if ((x - y) % d) {
        cout << "Impossible" << endl;
    } else {
        p *= (x - y) / d;
        l /= d;
        p = (p % l + l) % l;
        cout << p << endl;
    }
    return 0;
}


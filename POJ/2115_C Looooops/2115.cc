#include <iostream>
#include <cmath>

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

int main() {
    long long A, B, C, K;
    while (cin >> A >> B >> C >> K and A + B + C + K) {
        // x * C + y * 2^K = B - A
        long long a = C, b = pow(2, K), c = B - A;

        long long x, y, d = gcd(a, b);
        if (c % d) {
            cout << "FOREVER" << endl;
            continue;
        }
        extended_gcd(a, b, x, y);
        x *= c / d;
        b /= d;
        cout << (x % b + b) % b << endl;
    }
    return 0;
}


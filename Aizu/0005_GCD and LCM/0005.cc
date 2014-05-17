#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int t;
    while (b) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {

    int a, b;
    int r1, r2;
    while (cin >> a >> b) {
        r1 = gcd(a, b);
        r2 = a / r1 * b;
        cout << r1 << " " << r2 << endl;
    }

    return 0;
}

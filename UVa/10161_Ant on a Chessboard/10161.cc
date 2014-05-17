#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        int var = sqrt(n);
        int rem = n - var * var;
        int x, y;
        if (rem == 0) {
            x = 1;
            y = var;
        } else if (rem <= var + 1) {
            x = rem;
            y = var + 1;
        } else {
            x = var + 1;
            y = 2 * var + 1 - rem + 1;
        }

        if (var % 2)
            cout << x << " " << y << endl;
        else
            cout << y << " " << x << endl;
    }

    return 0;
}

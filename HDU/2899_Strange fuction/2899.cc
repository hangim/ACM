#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(double x, double y) {
    return 42 * pow(x, 6) + 48 * pow(x, 5) + 21 * pow(x, 2)
        + 10 * x - y;
}

double f(double x, double y) {
    return 6 * pow(x, 7) + 8 * pow(x, 6) + 7 * pow(x, 3)
        + 5 * pow(x, 2) - y * x;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        double y;
        cin >> y;

        double l = 0;
        double r = 100;
        while (r - l > 1e-9) {
            double mid = l + (r - l) / 2;
            double var = g(mid, y);
            if (fabs(var) < 1e-9)
                l = r = mid;
            else if (var > 0)
                r = mid;
            else
                l = mid;
        }

        cout << setprecision(4) << fixed << f(r, y) << endl;
    }

    return 0;
}


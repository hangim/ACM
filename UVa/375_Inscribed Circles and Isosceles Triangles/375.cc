#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double pi = acos(-1);

    int t;
    cin >> t;
    while (t--) {
        double b, h;
        cin >> b >> h;

        double s2 = b * h;
        double a = sqrt(pow(b / 2, 2) + pow(h, 2));
        double sum = 0;
        double r = s2 / (b + 2 * a);

        while (r > 1e-6) {
            sum += 2 * pi * r;
            b *= (h - 2 * r) / h;
            a *= (h - 2 * r) / h;
            h -= 2 * r;
            s2 = b * h;
            r = s2 / (b + 2 * a);
        }

        cout << setw(13) << setfill(' ') << setiosflags(ios::right)
             << setprecision(6) << fixed << sum << endl;

        if (t)
            cout << endl;
    }

    return 0;
}

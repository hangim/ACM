#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    float a, b, c;
    float d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f) {
        float t = a * e - b * d;

        float x1 = (c * e - b * f) / t;
        float x2 = (a * f - c * d) / t;

/*
    Hint
        try it

            2 -1 -3 1 -1 -3
            2 -1 -3 -9 9 27

        output should be

            0.000 3.000
            0.000 3.000
*/
        if (fabs(x1) < 1e-4)
            x1 = 0;
        if (fabs(x2) < 1e-4)
            x2 = 0;

        cout << setprecision(3) << fixed << x1 << " " << x2 << endl;
    }

    return 0;
}

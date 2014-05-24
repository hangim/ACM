#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int a, b, s, m, n;
    while (cin >> a >> b >> s >> m >> n) {
        if (a + b + s + m + n == 0)
            break;
    
        double x = m * a;
        double y = n * b;

        double v = sqrt(x * x + y * y) / s;
        double degree = atan(y / x) * 180.0 / acos(-1);

        cout << setprecision(2) << fixed << degree
             << " " << setprecision(2) << fixed << v << endl;
    }

    return 0;
}

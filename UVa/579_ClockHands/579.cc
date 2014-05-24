#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int h, m;
    char split;

    while (cin >> h >> split >> m) {
        if (h == 0)
            break;

        double hour = 360.0 * (h * 60 + m) / 720.0;
        double minute = 360.0 * m / 60.0;
        double ans = hour - minute + 360.0;
        while (ans >= 360.0)
            ans -= 360.0;
        if (ans > 180.0)
            ans = 360.0 - ans;

        cout << setprecision(3) << fixed << ans << endl;

    }

    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        if (x1 == x2 and y1 == y2)
            cout << "Impossible" << endl;

        cout << setprecision(10) << fixed
             << (x1 + x2 + y2 - y1) / 2 << " "
             << setprecision(10) << fixed
             << (y1 + y2 + x1 - x2) / 2 << " "
             << setprecision(10) << fixed
             << (x1 + x2 + y1 - y2) / 2 << " "
             << setprecision(10) << fixed
             << (y1 + y2 + x2 - x1) / 2 << endl;
    }

    return 0;
}

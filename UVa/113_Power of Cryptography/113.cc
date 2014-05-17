#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    double n, p;

    while (cin >> n >> p) {
        cout << setprecision(0) << fixed << pow(p, 1 / n) << endl;
    }

    return 0;
}

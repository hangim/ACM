#include <iostream>
#include <cmath>

using namespace std;

int lastCost(int d, int t) {
    if (d <= 3)
        return round(1 + 10 + 2.0 * t / 5);
    if (d <= 10)
        return round(1 + 10 + 2 * (d - 3) + 2.0 * t / 5);
    return round(1 + 10 + 2 * (10 - 3) + 3 * (d - 10) + 2.0 * t / 5);
}

int nowCost(int d, int t) {
    if (d <= 3)
        return round(11 + 2.5 * t / 4);
    if (d <= 10)
        return round(11 + 2.5 * (d - 3) + 2.5 * t / 4);
    return round(11 + 2.5 * (10 - 3) + 3.75 * (d - 10) + 2.5 * t / 4);
}

int main() {

    int n;
    cin >> n;
    while (n--) {
        int d, t;
        cin >> d >> t;
        cout << nowCost(d, t) - lastCost(d, t) << endl;
    }

    return 0;
}

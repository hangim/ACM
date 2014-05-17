#include <iostream>

using namespace std;

int T1, T2, P1, P2, P3;

int calc(int t) {
    if (t >= 0 and t <= T1)
        return P1 * t;

    if (t >= T1 and t <= T1 + T2)
        return P1 * T1 + P2 * (t - T1);

    return P1 * T1 + P2 * T2 + P3 * (t - T1 - T2);
}

int main() {

    int n;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
    int cost = 0;

    int var1, var2;
    cin >> var1 >> var2;
    cost += (var2 - var1) * P1;

    for (int i = 1; i < n; i++) {
        cin >> var1;
        cost += calc(var1 - var2);
        cin >> var2;
        cost += (var2 - var1) * P1;
    }

    cout << cost << endl;

    return 0;
}

#include <iostream>

using namespace std;

int x[1001], y[1001], z[1001];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool check(int i, int j) {
    int l = y[j] - z[i];
    int r = z[j] - y[i];
    int d = gcd(x[i], x[j]);
    if (l % d == 0 or r % d == 0)
        return true;
    else
        return l / d != r / d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i] >> z[i];
        
        bool flag = true;
        for (int i = 0; flag and i < n; ++i) {
            for (int j = i + 1; flag and j < n; ++j) {
                if (check(i, j)) {
                    flag = false;
                }
            }
        }

        cout << (flag ? "Can Take off" : "Cannot Take off") << endl;
    }

    return 0;
}


#include <iostream>
#include <cmath>

using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {

    int n, x0;
    cin >> n >> x0;
    int r[1001] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int t = a < b? a : b;
        b = a > b ? a : b;
        a = t;
        for (int j = a; j <= b; j++)
            r[j] += 1;
    }

    int minn = 1000;
    for (int i = 0; i <= 1000; i++)
        if (r[i] == n)
            minn = min(minn, abs(x0 - i));

    if (minn == 1000)
        cout << -1 << endl;
    else
        cout << minn << endl;

    return 0;
}

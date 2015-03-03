#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int A, B;
    A = min(n / 2, m);
    B = 0;
    n -= 2 * A;
    m -= A;

    if (n == 1 and m >= 2) {
        B = 1;
        n -= 1;
        m -= 2;
    }

    cout << A + B + min(A, m / 3) << endl;

    return 0;
}


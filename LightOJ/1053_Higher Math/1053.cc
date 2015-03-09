#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        int a, b, c;
        cin >> a >> b >> c;
        a *= a;
        b *= b;
        c *= c;
        cout << "Case " << k << ": ";
        if (a + b == c or  a + c == b or b + c == a)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 1 << endl;
    else if (m * 2 <= n)
        cout << m + 1 << endl;
    else
        cout << m - 1 << endl;
    return 0;
}


#include <iostream>

using namespace std;

long long fun(int n, int m) {
    long long c = 1;
    for (int i = n; i > n - m; i--)
        c *= i;
    for (int i = 2; i <= m; i++)
        c /= i;
    return c;
}

int main() {

    long long memo[21] = {0, 0, 1};
    for (int i = 3; i < 21; i++)
        memo[i] = (i - 1) * (memo[i-1] + memo[i-2]);

    int c;
    cin >> c;
    while (c--) {
        int n, m;
        cin >> n >> m;
        cout << memo[m] * fun(n, m) << endl;
    }

    return 0;
}

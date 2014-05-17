#include <iostream>

using namespace std;

int main() {

    long long n, m, a;
    cin >> n >> m >> a;

    long long x = n / a, y = m / a;
    if (x * a < n)
        x++;
    if (y * a < m)
        y++;

    cout << x * y << endl;

    return 0;
}

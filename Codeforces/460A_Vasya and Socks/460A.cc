#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (n >= m) {
        ans += m;
        n -= m - 1;
    }
    ans += n;
    cout << ans << endl;

    return 0;
}


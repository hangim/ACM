#include <iostream>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    s *= 100;

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int t = x * 100 + y;
        if (t <= s) {
            if (t % 100)
                ans = max(ans, 100 - t % 100);
            else
                ans = max(ans, 0);
        }
    }

    cout << ans << endl;

    return 0;
}


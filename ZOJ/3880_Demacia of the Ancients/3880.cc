#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n--) {
            int x;
            cin >> x;
            if (x > 6000)
                ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}

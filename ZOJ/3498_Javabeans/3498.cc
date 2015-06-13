#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n) {
            ++ans;
            n /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1)
            ans = -1;
    }
    cout << ans << endl;

    return 0;
}


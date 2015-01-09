#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int ans = 0;

    while (n--) {
        int num;
        cin >> num;
        if (num % k == 0)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}


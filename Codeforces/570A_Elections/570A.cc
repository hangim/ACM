#include <bits/stdc++.h>

using namespace std;

int cnt[110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int index = 1, maxx = 0, x;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            if (x > maxx) {
                index = j;
                maxx = x;
            }
        }
        cnt[index]++;
    }

    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        if (cnt[i] > cnt[ans])
            ans = i;
    }
    cout << ans << endl;
    return 0;
}


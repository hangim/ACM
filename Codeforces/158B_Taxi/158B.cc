#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt[5] = {0};
    for (int i = 0; i < n; i++) {
        int var;
        cin >> var;
        cnt[var]++;
    }

    int ans = cnt[4];
    
    ans += cnt[3];
    cnt[1] -= cnt[3];

    ans += cnt[2] / 2;
    if (cnt[2] % 2) {
        ans++;
        cnt[1] -= 2;
    }

    if (cnt[1] > 0) {
        ans += cnt[1] / 4;
        if (cnt[1] % 4)
            ans++;
    }

    cout << ans << endl;

    return 0;
}


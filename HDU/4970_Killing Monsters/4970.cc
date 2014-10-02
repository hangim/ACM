#include <iostream>
#include <cstring>

using namespace std;

long long num[100002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n and n) {
        memset(num, 0, sizeof(num));
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int l, r;
            long long d;
            cin >> l >> r >> d;
            num[l-1] -= d;
            num[r] += d;
        }

        long long tmp = 0;
        for (int i = n; i >= 1; i--) {
            tmp += num[i];
            num[i] = tmp + num[i+1];
        }

        int k;
        cin >> k;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            long long hp;
            int x;
            cin >> hp >> x;
            if (hp > num[x])
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}


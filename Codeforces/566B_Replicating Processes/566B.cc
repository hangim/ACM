#include <bits/stdc++.h>

using namespace std;

const int maxn = 30000;
int a[4 * maxn + 10], b[4 * maxn + 10], c[4 * maxn + 10];
int ans[4 * maxn + 10], vis[4 * maxn + 10];
int cnt[maxn + 10], m;

void f(int n) {
    m = 0;
    while (true) {
        bool flag = true;
        for (int i = 1; i <= 4 * n; ++i) {
            if (vis[i]) continue;
            if ((b[i] == c[i] and cnt[b[i]] + 2 <= 5)
                or (b[i] != c[i] and cnt[b[i]] + 1 <= 5 and cnt[c[i]] + 1 <= 5)) {
                --cnt[a[i]];
                ++cnt[b[i]];
                ++cnt[c[i]];
                ans[m++] = i;
                vis[i] = 1;
                flag = false;
            }
        }
        if (flag)
            return;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= 4 * n; ++i)
        cin >> a[i] >> b[i] >> c[i];
    f(n);

    if (m != 4 * n)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        copy(ans, ans + 4 * n, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}


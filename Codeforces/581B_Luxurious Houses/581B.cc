#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int cnt[maxn + 10], ans[maxn + 10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> cnt[i];

    ans[n] = 0;
    for (int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i+1], cnt[i+1]);
    
    for (int i = 1; i <= n; ++i)
        cout << max(ans[i] - cnt[i] + 1, 0) << " ";
    cout << endl;
    return 0;
}


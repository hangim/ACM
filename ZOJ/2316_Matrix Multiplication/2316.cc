#include <iostream>
#include <cstring>

using namespace std;

long long cnt[10001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            cnt[u]++;
            cnt[v]++;
        }
        
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            ans += cnt[i] * cnt[i];
        cout << ans << endl;
        if (t)
            cout << endl;
    }

    return 0;
}


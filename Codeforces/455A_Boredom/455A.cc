#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> cnt(100001, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int var;
        cin >> var;
        cnt[var]++;
        mx = max(mx, var);
    }

    vector<long long> ans(mx+1, 0);
    ans[0] = 0;
    ans[1] = 1 * cnt[1];
    for (int i = 2; i <= mx; i++)
        ans[i] = max(ans[i-1], ans[i-2] + (long long)i * (long long)cnt[i]);

    cout << ans[mx] << endl;

    return 0;
}


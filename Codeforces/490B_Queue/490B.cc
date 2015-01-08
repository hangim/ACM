#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    map<int, int> front, behind;
    set<int> s;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        behind[u] = v;
        front[v] = u;
        s.insert(u);
        s.insert(v);
    }

    vector<int> ans(n+2, 0);

    for (int i = 0; i + 2 < n + 2; i += 2) {
        ans[i+2] = behind[ans[i]];
        s.erase(s.find(behind[ans[i]]));
    }

    int p = *s.begin();
    while (front[p] != 0)
        p = front[p];
    ans[1] = p;
    for (int i = 1; i + 2 < n + 2; i += 2)
        ans[i+2] = behind[ans[i]];

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}

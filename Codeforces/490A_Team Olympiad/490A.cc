#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector<int> v[3];
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            v[t-1].push_back(i + 1);
        }
        
        int w = min(min(v[0].size(), v[1].size()), v[2].size());
        cout << w << endl;
        for (int i = 0; i < w; ++i) {
            cout << v[0][i] << " " << v[1][i] << " " << v[2][i] << endl;
        }
    }

    return 0;
}


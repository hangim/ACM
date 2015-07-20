#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int n;
        cin >> n;
        int cnt = 0;
        double q = 1;
        while (q > 0.5) {
            ++cnt;
            q *= 1 - 1.0 * cnt / n;
        }
        cout << "Case " << cases << ": " << cnt << endl;
    }
    return 0;
}

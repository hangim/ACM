#include <bits/stdc++.h>

using namespace std;

int P[1010];

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int D;
        cin >> D;

        int maxP = 0;
        for (int i = 0; i != D; ++i) {
            cin >> P[i];
            maxP = max(maxP, P[i]);
        }

        int ans = INT_MAX;
        for (int i = 1; i <= maxP; ++i) {
            int cnt = i;
            for (int j = 0; j != D; ++j) {
                if (P[j] > i) {
                    cnt += (P[j] - i + i - 1) / i;
                }
            }
            ans = min(ans, cnt);
        }

        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}


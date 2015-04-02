#include <iostream>
#include <algorithm>

using namespace std;

int num[1010], dp[1010];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i != n; ++i) {
            cin >> num[i];
            dp[i] = 1;
        }
        for (int i = 0; i != n; ++i) {
            for (int j = i + 1; j != n; ++j) {
                if (num[i] < num[j] and dp[i] + 1 > dp[j])
                    dp[j] = dp[i] + 1;
            }
        }
        int ans = *max_element(dp, dp + n);
        cout << ans << endl;
    }
    return 0;
}


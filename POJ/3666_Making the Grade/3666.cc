#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
    
int A[2000] = {0};
int B[2000] = {0};
int dp[2000] = {0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    copy(A, A + n, B);
    sort(B, B + n);

    for (int i = 0; i < n; i++) {
        int minn = dp[0];
        for (int j = 0; j < n; j++) {
            minn = min(minn, dp[j]);
            dp[j] = minn + abs(A[i] - B[j]);
        }
    }
    
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;

    return 0;
}


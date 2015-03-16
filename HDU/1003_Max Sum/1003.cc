#include <bits/stdc++.h>

using namespace std;

int A[100010];

int main() {
    int t;
    cin >> t;
    for (int k = 1; t; k++, t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> A[i];
        int s = 1, e = 1, pos = 1;

        int sum = A[1], ans = A[1];
        for (int i = 2; i <= n; ++i) {
            sum += A[i];
            if (sum < A[i])
                sum = A[i], pos = i;
            if (sum > ans)
                ans = sum, s = pos, e = i;
        }
        if (k != 1)
            cout << endl;
        cout << "Case " << k << ":" << endl;
        cout << ans << " " << s << " " << e << endl;
    }
}

#include <bits/stdc++.h>

using namespace std;

int A[2010], B[2010], dp[2010];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; ++i)
            cin >> A[i];
        for (int i = 2; i <= k; ++i)
            cin >> B[i];

        memset(dp, 0, sizeof(dp));
        dp[1] = A[1];
        for (int i = 2; i <= k; ++i)
            dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);
        
        int HH = 8 + dp[k] / 3600;
        int MM = dp[k] / 60 % 60;
        int SS = dp[k] % 60;
        string suffix = HH < 12 ? " am" : " pm";
        if (HH > 12)
            HH %= 12;
        cout << setfill('0')
             << setw(2) << HH << ":"
             << setw(2) << MM << ":"
             << setw(2) << SS << suffix << endl;
    }

    return 0;
}


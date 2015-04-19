#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int Smax;
        string str;
        cin >> Smax >> str;
        int ans = 0, cnt = 0;
        for (int i = 0; i != str.length(); ++i) {
            if (cnt < i) {
                ans += i - cnt;
                cnt = i;
            }
            cnt += str[i] - '0';
        }
        cout << "Case #" << cases << ": " << ans << endl;
    }
    return 0;
}


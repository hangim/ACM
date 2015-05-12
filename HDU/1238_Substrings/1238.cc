#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string str[100];
        for (int i = 0; i != n; ++i)
            cin >> str[i];
        
        int ans;
        for (ans = str[0].length(); ans > 0; --ans) {
            bool flag1 = false;
            for (int i = 0; i + ans <= str[0].length(); ++i) {
                bool flag2 = true;
                string tmp1 = str[0].substr(i, ans);
                string tmp2(tmp1.rbegin(), tmp1.rend());
                for (int j = 1; j != n; ++j) {
                    if (str[j].find(tmp1) == str[j].npos and str[j].find(tmp2) == str[j].npos) {
                        flag2 = false;
                        break;
                    }
                }
                if (flag2) {
                    flag1 = true;
                    break;
                }
            }
            if (flag1)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}

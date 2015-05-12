#include <bits/stdc++.h>

using namespace std;

string s[4010];

int main() {
    int n;
    while (cin >> n and n) {
        for (int i = 0; i != n; ++i)
            cin >> s[i];

        string ans = "";

        for (int i = s[0].length(); i > 0; --i) {
            bool flag1 = false;
            for (int j = 0; j + i <= s[0].length(); ++j) {
                bool flag2 = true;
                string tmp = s[0].substr(j, i);
                for (int k = 1; k != n; ++k) {
                    if (s[k].find(tmp, 0) == s[k].npos) {
                        flag2 = false;
                        break;
                    }
                }
                if (flag2) {
                    flag1 = true;
                    if (ans == "" or tmp < ans)
                        ans = tmp;
                }
            }
            if (flag1)
                break;
        }

        if (ans == "")
            cout << "IDENTITY LOST" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}


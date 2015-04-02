#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        vector<vector<int> > dp(str1.length() + 1);
        for (int i = 0; i != dp.size(); ++i)
            dp[i] = vector<int>(str2.length() + 1);

        for (int i = 0; i != str1.length(); ++i) {
            for (int j = 0; j != str2.length(); ++j) {
                dp[i+1][j+1] = max(dp[i][j] + (int)(str1[i] == str2[j]),
                        max(dp[i][j+1], dp[i+1][j]));
            }
        }

        int ans = 0;
        for (int i = 0; i != dp[str1.length()].size(); ++i)
            ans = max(ans, dp[str1.length()][i]);
        cout << ans << endl;
    }
    return 0;
}


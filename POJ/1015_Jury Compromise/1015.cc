#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int OFFSET = 400;
int P[201], D[201];
int diff[201], sum[201];
int dp[21][801], path[21][801];

bool select(int i, int j, int k) {
    while (path[i][j] != -1) {
        if (path[i][j] == k)
            return false;
        j -= diff[path[i][j]];
        --i;
    }
    return true;
}

int main() {
    int n, m;
    int cases = 1;
    while (cin >> n >> m and n + m) {
        for (int i = 0; i != n; ++i) {
            cin >> P[i] >> D[i];
            diff[i] = P[i] - D[i];
            sum[i] = P[i] + D[i];
        }

        memset(dp, -1, sizeof(dp));
        memset(path, -1, sizeof(path));
        
        dp[0][OFFSET] = 0;

        for (int i = 0; i != m; ++i) {
            for (int j = 0; j <= 2 * OFFSET; ++j) {
                if (dp[i][j] == -1)
                    continue;
                for (int k = 0; k != n; ++k) {
                    if (dp[i][j] + sum[k] > dp[i+1][j + diff[k]] and select(i, j, k)) {
                        path[i+1][j + diff[k]] = k;
                        dp[i+1][j + diff[k]] = dp[i][j] + sum[k];
                    }
                }
            }
        }

        int x;
        for (int i = 0; i <= OFFSET; ++i) {
            if (dp[m][OFFSET + i] >= 0 or dp[m][OFFSET - i] >= 0) {
                x = i;
                break;
            }
        }
        x = dp[m][OFFSET - x] > dp[m][OFFSET + x] ? OFFSET - x : OFFSET + x;

        vector<int> ans;
        int i = m, j = x;
        while (path[i][j] != -1) {
            ans.push_back(path[i][j]);
            j -= diff[path[i][j]];
            --i;
        }

        sort(ans.begin(), ans.end());
        int prosecution = 0, defence = 0;
        for (int i = 0; i != ans.size(); ++i) {
            prosecution += P[ans[i]];
            defence += D[ans[i]];
        }
        
        cout << "Jury #" << cases++ << endl;
        cout << "Best jury has value " << prosecution
             << " for prosecution and value " << defence
             << " for defence:" << endl;
        for (int i = 0; i != ans.size(); ++i)
            cout << " " << ans[i] + 1;
        cout << endl << endl;
    }
    return 0;
}



#include <bits/stdc++.h>

using namespace std;

int w[26 + 'a'];
vector<int> pos[26 + 'a'];
long long sum[100001];

int main() {
    for (int c = 'a'; c <= 'z'; ++c)
        cin >> w[c];
    string s;
    cin >> s;

    sum[0] = w[s[0]];
    pos[s[0]].push_back(0);
    for (int i = 1; i != s.size(); ++i) {
        sum[i] = sum[i-1] + w[s[i]];
        pos[s[i]].push_back(i);
    }

    long long ans = 0;
    for (int c = 'a'; c <= 'z'; ++c) {
        map<long long, int> m;
        for (int i = 0; i != pos[c].size(); ++i) {
            int p = pos[c][i];
            if (p != 0)
                ans += m[sum[p-1]];
            ++m[sum[p]];
        }
    }

    cout << ans << endl;

    return 0;
}


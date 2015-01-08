#include <bits/stdc++.h>

using namespace std;

vector<string> v;

bool dfs(int i, int j, bool isBig) {
    if (j == v[i].length())
        return isBig;

    if (v[i][j] == '?') {
        if (isBig) {
            v[i][j] = '0';
            return dfs(i, j + 1, true);
        } else {
            for (int c = v[i-1][j]; c <= '9'; ++c) {
                v[i][j] = c;
                if (dfs(i, j + 1, c > v[i-1][j]))
                    return true;
            }
            v[i][j] = '?';
            return false;
        }
    } else {
        if (not isBig and v[i][j] < v[i-1][j])
            return false;
        return dfs(i, j + 1, isBig or v[i][j] > v[i-1][j]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    v.resize(n+1);
    v[0] = "";

    for (int i = 1; i <= n; ++i) {
        string str;
        cin >> str;
        v[i] = str;
    }

    bool flag = true;
    for (int i = 1; flag and i <= n; ++i) {
        if (v[i].length() < v[i-1].length())
            flag = false;
        else if (v[i].length() == v[i-1].length()) {
            flag = dfs(i, 0, false);
        } else {
            v[i][0] = v[i][0] == '?' ? '1' : v[i][0];
            for (int j = 1; j != v[i].length(); ++j)
                v[i][j] = v[i][j] == '?' ? '0' : v[i][j];
        }
    }

    if (flag) {
        cout << "YES" << endl;
        copy(++v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


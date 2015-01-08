#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    int a, b;
    cin >> a >> b;

    vector<int> v1(str.size()), v2(str.size());

    for (int i = 0, rem = 0; i != str.size(); ++i) {
        v1[i] = rem = (rem * 10 + str[i] - '0') % a;
    }

    for (int i = str.size() - 1, base = 1, rem = 0; i > 0; --i) {
        v2[i] = rem = ((str[i] - '0') * base + rem) % b;
        base = base * 10 % b;

        if (v2[i] == 0 and str[i] != '0' and v1[i-1] == 0) {
            cout << "YES" << endl
                 << str.substr(0, i) << endl
                 << str.substr(i, str.size() - i) << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    
    return 0;
}


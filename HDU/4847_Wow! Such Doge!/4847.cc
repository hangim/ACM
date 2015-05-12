#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
    int ans = 0;
    string str;
    while (cin >> str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        int pos = 0;
        while ((pos = str.find("doge", pos)) != str.npos) {
            ++pos;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}

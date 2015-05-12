#include <iostream>
#include <vector>
#include <cstring>
#include <iterator>
#include <algorithm>

using namespace std;

const int MAXN = 1000010;

int len;
char s[MAXN];
int Next[MAXN];

void get_next() {
    int k = Next[0] = -1, j = 0;
    while (j != len) {
        if (k == -1 or s[j] == s[k])
            Next[++j] = ++k;
        else
            k = Next[k];
    }
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cin >> s;
        len = strlen(s);
        get_next();
        vector<int> v;
        int ans = 0;
        for (int i = Next[len]; i; i = Next[i]) {
            ++ans;
            v.push_back(len - i);
        }
        cout << "Case #" << cases << ": " << ans + 1 << endl;
        copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
        cout << len << endl;
    }
    return 0;
}


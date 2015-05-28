#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int len, l, r;
} s[55];

int main() {
    int n;
    while (cin >> n and n) {
        for (int i = 1; i <= n; ++i) {
            cin >> s[i].len;
            s[i].l = 0;
            for (int j = 1; j != i; ++j)
                s[i].l = max(s[i].l, s[j].r - abs(s[i].len - s[j].len));
            s[i].r = s[i].l + 2 * s[i].len;
        }

        bool first = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j)
                if (s[i].l < s[j].r and s[i].len < s[j].len)
                    s[i].l = s[j].r;
            for (int j = i + 1; j <= n; ++j)
                if (s[i].r > s[j].l and s[i].len < s[j].len)
                    s[i].r = s[j].l;
            if (s[i].l < s[i].r) {
                cout << (first ? "" : " ") << i;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}


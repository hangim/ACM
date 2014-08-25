#include <iostream>
#include <cstring>

using namespace std;

int p[10001];

inline int getLen(int x) {
    int len = 0;
    while (p[x]) {
        len++;
        x = p[x];
    }
    return len;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(p, 0, sizeof(p));

        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            p[v] = u;
        }

        int x, y;
        cin >> x >> y;
        int len1 = getLen(x);
        int len2 = getLen(y);
        while (len1 > len2) {
            x = p[x];
            len1--;
        }
        while (len2 > len1) {
            y = p[y];
            len2--;
        }
        while (x != y) {
            x = p[x];
            y = p[y];
        }

        cout << x << endl;
    }

    return 0;
}


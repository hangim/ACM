#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int pre[10001];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(pre, 0, sizeof(pre));
        int n;
        cin >> n;
        for (int i = 0; i < n-1; i++) {
            int p, q;
            cin >> p >> q;
            pre[q] = p;
        }

        int a, b;
        cin >> a >> b;
        set<int> s;
        while (a) {
            s.insert(a);
            a = pre[a];
        }

        while (b) {
            if (s.find(b) != s.end()) {
                cout << b << endl;
                break;
            }
            b = pre[b];
        }
    }

    return 0;
}

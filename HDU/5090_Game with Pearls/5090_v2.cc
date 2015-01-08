#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        vector<int> cnt(n+1);
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            for ( ; t <= n; t += k)
                cnt[t]++;
        }

        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] <= 0) {
                flag = false;
                break;
            }
            for (int t = i; t <= n; t += k)
                --cnt[t];
        }
        cout << (flag ? "Jerry" : "Tom") << endl;
    }

    return 0;
}


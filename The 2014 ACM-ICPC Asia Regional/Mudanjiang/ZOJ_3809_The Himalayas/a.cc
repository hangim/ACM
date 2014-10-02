#include <iostream>

using namespace std;

int m[51];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> m[i];

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            if (m[i-1] < m[i] and m[i] > m[i+1])
                ans++;

        cout << ans << endl;
    }

    return 0;
}


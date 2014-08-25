// Wrong Answer
#include <iostream>

using namespace std;

long long num[3000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        long long ans = num[n-1];
        long long flag = -1;
        long long k = 1;
        for (int i = 1; i < n; i++) {
            k = k * (n-i) / i;
            ans += flag * k * num[n-1-i];
            flag *= -1;
        }
        cout << ans << endl;
    }

    return 0;
}


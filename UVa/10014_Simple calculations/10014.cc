#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
    
        int n;
        cin >> n;
        double a0, al;
        cin >> a0 >> al;

        double ans = n * a0 + al;

        for (int i = 0; i < n; i++) {
            double c;
            cin >> c;
            ans -= 2 * (n - i) * c;
        }

        ans /= (n + 1);

        cout << setprecision(2) << fixed << ans << endl;
        if (t)
            cout << endl;
    }

    return 0;
}

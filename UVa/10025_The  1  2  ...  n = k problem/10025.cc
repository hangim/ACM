#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        k = k > 0 ? k : -k;

        int n = sqrt(2 * k);
        int sum = n * (n + 1) / 2;
        while (true) {
            if (sum >= k and (sum - k) % 2 == 0)
                break;
            sum += ++n;
        }

        if (k == 0)
            n = 3;

        cout << n << endl;

        if (t)
            cout << endl;
    }

}

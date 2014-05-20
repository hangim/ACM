#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        int bitLen = 4 * round(pow(2, (n - 1960) / 10));
        
        double var = 1;
        double k = 1;
        for (int i = 1; i <= bitLen; i++) {
            var *= 2;
            while (var > k) {
                var /= k;
                k++;
            }
        }
        cout << --k << endl;
    }

    return 0;
}

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {

    int n, b;
    while (cin >> n >> b) {
        double digits = 0;
        int *factor = new int[b+1];
        memset(factor, 0, sizeof(factor));

        for (int i = 2; i <= n; i++) {
            digits += log(i) / log(b);
        
            int var = i;
            for (int j = 2; j <= b; j++) {
                while (var % j == 0) {
                    var /= j;
                    factor[j]++;
                }
            }
        }

        int zeros = 0;
        while (true) {
            int var = b;
            for (int i = 2; i <= b; i++) {
                while (factor[i] and var % i == 0) {
                    factor[i]--;
                    var /= i;
                }
            }

            if (var == 1)
                zeros++;
            else
                break;
        }
        
        cout << zeros << " " << (int)floor(digits + 1e-9) + 1 << endl;
    }

    return 0;
}

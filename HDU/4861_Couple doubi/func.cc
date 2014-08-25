#include <iostream>

using namespace std;

int func(int k, int p) {
    int ans = 0;
    for (int i = 1; i < p; i++) {
        int var = 1;
        for (int j = 1; j <= k; j++) {
            var *= i;
            var %= p;
        }
        ans += var;
        ans %= p;
    }
    return ans;
}

int main() {

    int k, p;
    while (cin >> k >> p) {
        for (int i = 1; i <= k; i++) {
            cout << func(i, p) << " ";
        }
        cout << endl;
    }

    return 0;
}


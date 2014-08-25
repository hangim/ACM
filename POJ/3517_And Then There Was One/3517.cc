#include <iostream>

using namespace std;

int main() {
    int n, k, m;
    while (cin >> n >> k >> m and n + k + m) {
        int s = 0; // F[1] = 0
        for (int i = 2; i < n; i++) {
            s = (s + k) % i; // F[i] = (F[i-1] + k) % i
        }
        cout << (s + m) % n + 1 << endl;
    }

    return 0;
}


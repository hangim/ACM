#include <bits/stdc++.h>

using namespace std;

int main() {
    int c1[305], c2[305];

    int n;
    while (cin >> n and n) {
        for (int i = 0; i <= n; ++i) {
            c1[i] = 1;
            c2[i] = 0;
        }
        for (int i = 2; i * i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k + j <= n; k += i * i)
                    c2[k+j] += c1[j];
            }
            memcpy(c1, c2, sizeof(c2));
            memset(c2, 0, sizeof(c2));
        }

        cout << c1[n] << endl;
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8010;
int c1[MAXN], c2[MAXN], c3[MAXN];

int main() {
    int n1, n2, n3;
    while (cin >> n1 >> n2 >> n3 and n1 + n2 + n3) {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        memset(c3, 0, sizeof(c3));

        for (int i = 0; i <= n1; ++i)
            c1[i] = 1;
        for (int i = 0; i < MAXN; ++i) {
            for (int k = 0; k <= 2 * n2 and i + k < MAXN; k += 2)
                c2[i+k] += c1[i];
        }
        for (int i = 0; i < MAXN; ++i) {
            for (int k = 0; k <= 5 * n3 and i + k < MAXN; k += 5)
                c3[i+k] += c2[i];
        }

        for (int i = 1; i < MAXN; ++i) {
            if (c3[i] == 0) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}


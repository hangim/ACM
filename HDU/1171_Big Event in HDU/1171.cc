#include <bits/stdc++.h>

using namespace std;

int V[55], M[55];

int c1[250000], c2[250000];

int main() {
    int n;
    while (cin >> n and n > 0) {
        int sum = 0;
        for (int i = 0; i != n; ++i) {
            cin >> V[i] >> M[i];
            sum += V[i] * M[i];
        }

        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        c1[0] = 1;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                for (int k = 0; k <= V[i] * M[i] and k + j <= sum; k += V[i]) {
                    c2[k+j] += c1[j];
                }
            }
            memcpy(c1, c2, sizeof(c2));
            memset(c2, 0, sizeof(c2));
        }

        for (int ans = (sum + 1) / 2; ans <= sum; ++ans) {
            if (c1[ans] and c1[sum-ans]) {
                cout << ans << " " << sum - ans << endl;
                break;
            }
        }
    }

    return 0;
}


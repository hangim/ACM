#include <cstdio>
#include <bitset>

using namespace std;

bitset<800> A1[800], A2[800], B1[800], B2[800];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            A1[i].reset();
            A2[i].reset();
            B1[i].reset();
            B2[i].reset();
        }

        int var;
        // input A
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &var);
                var %= 3;
                if (var == 1)
                    A1[i][j] = 1;
                else if (var == 2)
                    A2[i][j] = 1;
            }
        }

        // input B
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &var);
                var %= 3;
                if (var == 1)
                    B1[j][i] = 1;
                else if (var == 2)
                    B2[j][i] = 1;
            }
        }

        // calc and output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                var = (A1[i]&B1[j]).count()
                    + (A2[i]&B2[j]).count()
                    + 2 * (A1[i]&B2[j]).count()
                    + 2 * (A2[i]&B1[j]).count();
                printf("%d%c", var % 3, j == n-1 ? '\n' : ' ');
            }
        }
    }

    return 0;
}


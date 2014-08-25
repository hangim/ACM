#include <cstdio>
#include <cstring>

using namespace std;

int A[800][800];
int B[800][800];
int C[800][800];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        // input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &A[i][j]);
                A[i][j] %= 3;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &B[i][j]);
                B[i][j] %= 3;
            }
        }

        // calc
        memset(C, 0, sizeof(C));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0)
                    continue;
                for (int k = 0; k < n; k++) {
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        }

        // output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++)
                printf("%d ", C[i][j] % 3);
            printf("%d\n", C[i][n-1] % 3);
        }
    }

    return 0;
}


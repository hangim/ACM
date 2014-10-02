#include <iostream>
#include <cstring>

using namespace std;

long long matrix[2002][2002];
long long principal[4001];
long long secondary[4001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    memset(matrix, 0, sizeof(matrix));
    memset(principal, 0, sizeof(principal));
    memset(secondary, 0, sizeof(secondary));

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
            principal[i-j+n] += matrix[i][j];
            secondary[i+j] += matrix[i][j];
        }
    }

    int x1 = 1, y1 = 1, x2 = 1, y2 = 2;
    long long max1 = 0, max2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long t = principal[i-j+n] + secondary[i+j] - matrix[i][j];
            if ((i + j) % 2 == 0 and t > max1) {
                max1 = t, x1 = i, y1 = j;
            }
            if ((i + j) % 2 == 1 and t > max2) {
                max2 = t, x2 = i, y2 = j;
            }
        }
    }

    cout << max1 + max2 << endl;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    return 0;
}


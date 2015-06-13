#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;
const int mod = 6;
typedef int Mat[maxn][maxn];

int N, K;
Mat A, B, X, Y, tmp;

void mul_mat(Mat ret, Mat a, Mat b, int r, int s, int t) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < t; ++j)
            for (int k = 0; k < s; ++k)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
    memcpy(ret, tmp, sizeof(tmp));
}

void pow_mat(Mat ret, Mat x, int n) {
    memset(Y, 0, sizeof(Y));
    for (int i = 0; i < K; ++i)
        Y[i][i] = 1;
    while (n) {
        if (n & 1)
            mul_mat(Y, Y, x, K, K, K);
        mul_mat(x, x, x, K, K, K);
        n >>= 1;
    }
    memcpy(ret, Y, sizeof(Y));
}

int main() {
    while (cin >> N >> K and N + K) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < K; ++j)
                cin >> A[i][j];
        for (int i = 0; i < K; i++)
            for (int j = 0; j < N; ++j)
                cin >> B[i][j];

        mul_mat(X, B, A, K, N, K);
        pow_mat(X, X, N * N - 1);
        mul_mat(X, A, X, N, K, K);
        mul_mat(X, X, B, N, K, N);
        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                ans += X[i][j];
        cout << ans << endl;
    }
    return 0;
}


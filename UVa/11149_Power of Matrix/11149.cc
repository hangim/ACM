#include <bits/stdc++.h>

using namespace std;

int n;

struct mat {
    int v[41][41];
    mat() {
        memset(v, 0, sizeof(v));
    }
    mat operator + (mat b) {
        mat c;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                c.v[i][j] = (v[i][j] + b.v[i][j]) % 10;
        return c;
    }
    mat operator * (mat b) {
        mat c;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    c.v[i][j] = (c.v[i][j] + v[i][k] * b.v[k][j]) % 10;
        return c;
    }
};

mat pow(mat a, int k) {
    mat c;
    for (int i = 0; i < n; ++i)
        c.v[i][i] = 1;
    while (k) {
        if (k & 1)
            c = c * a;
        a = a * a;
        k >>= 1;
    }
    return c;
}

mat sum(mat a, int k) {
    if (k == 1)
        return a;
    mat c;
    for (int i = 0; i < n; ++i)
        c.v[i][i] = 1;
    if (k == 0)
        return c;
    c = (c + pow(a, k / 2)) * sum(a, k / 2);
    if (k % 2)
        c = c + pow(a, k);
    return c;
}

int main() {
    int k;
    while (cin >> n >> k and n) {
        mat c;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> c.v[i][j];
                c.v[i][j] %= 10;
            }
        }
        c = sum(c, k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << c.v[i][j];
                if (j == n - 1)
                    cout << endl;
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


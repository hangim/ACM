#include <bits/stdc++.h>

using namespace std;

char mat[110][110];

int x[4], y[4];
bool vis[4];

void draw(int a, int b, int x0, int y0, int index) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j)
            mat[x0+i][y0+j] = 'A' + index - 1;
    }
}

bool dfs(int a, int b, int x0, int y0, int index) {
//    cout << a << " "<< b << " "<< x0 << " " << y0 << " " << index << endl;
    if (index == 4)
        return a == 0 or b == 0;

    for (int i = 1; i <= 3; i++) {
        if (vis[i]) continue;
        vis[i] = true;
        
        if (b == x[i] and a >= y[i]) {
            if (dfs(a - y[i], b, x0 + y[i], y0, index+1)) {
                draw(y[i], x[i], x0, y0, i);
                return true;
            }
        }
        if (b == y[i] and a >= x[i]) {
            if (dfs(a - x[i], b, x0 + x[i], y0, index+1)) {
                draw(x[i], y[i], x0, y0, i);
                return true;
            }
        }

        if (a == x[i] and b >= y[i]) {
            if (dfs(a, b - y[i], x0, y0 + y[i], index+1)) {
                draw(x[i], y[i], x0, y0, i);
                return true;
            }
        }
        if (a == y[i] and b >= x[i]) {
            if (dfs(a, b - x[i], x0, y0 + x[i], index+1)) {
                draw(y[i], x[i], x0, y0, i);
                return true;
            }
        }

        vis[i] = false;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int area = 0;
    for (int i = 1; i <= 3; ++i) {
        cin >> x[i] >> y[i];
        area += x[i] * y[i];
    }

    int n = sqrt(area) + 0.5;
    if (n * n != area) {
        cout << -1 << endl;
        return 0;
    }
//    cout << "area " << area << endl;

    if (dfs(n, n, 0, 0, 1)) {
        cout << n << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << mat[i][j];
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}


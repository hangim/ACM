#include <bits/stdc++.h>

using namespace std;

int a[10];

double p[10][2];

double cross(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 6; ++i)
        cin >> a[i];

    double s60 = sqrt(3) / 2, c60 = 1.0 / 2;

    p[0][0] = p[0][1] = p[6][0] = p[6][1] = 0;
    p[1][0] = a[1], p[1][1] = 0;
    p[2][0] = p[1][0] + a[2] * c60, p[2][1] = -a[2] * s60;
    p[3][0] = p[2][0] - a[3] * c60, p[3][1] = p[2][1] - a[3] * s60;
    p[4][0] = p[3][0] - a[4],       p[4][1] = p[3][1];
    p[5][0] = p[4][0] - a[5] * c60, p[5][1] = p[4][1] + a[5] * s60;

    double area = 0;
    for (int i = 0; i < 6; ++i)
        area += cross(p[i][0], p[i][1], p[i+1][0], p[i+1][1]);

    cout << (int)(fabs(area * 2 / sqrt(3)) + 1e-8) << endl;

    return 0;
}


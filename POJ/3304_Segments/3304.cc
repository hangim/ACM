#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-8;

bool dequal(double a, double b) {
    return fabs(a - b) < eps;
}

int dcmp(double x) {
    if (dequal(x, 0)) return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point() {};
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator == (const Point &o) const {
        return dequal(x, o.x) and dequal(y, o.y);
    }
};

struct Vector {
    double x, y;
    Vector() {};
    Vector(double _x, double _y) : x(_x), y(_y) {}
};

Vector operator - (Point a, Point b) {
    return Vector(a.x - b.x, a.y - b.y);
}

double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int n;
Point P[210];

bool func(Point a, Point b) {
    for (int k = 0; k != n; ++k) {
        int c1 = dcmp(cross(P[2*k] - a, b - a));
        int c2 = dcmp(cross(P[2*k+1] - a, b - a));
        if (c1 * c2 > 0)
            return false;
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i != 2 * n; ++i)
            cin >> P[i].x >> P[i].y;

        bool flag = false;
        for (int i = 0; i != 2 * n; ++i) {
            for (int j = i + 1; j != 2 * n; ++j) {
                if (P[i] == P[j]) continue;
                if (func(P[i], P[j]))
                    flag = true;
            }
            if (flag)
                break;
        }

        cout << (flag ? "Yes!" : "No!") << endl;
    }
}

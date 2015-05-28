#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

double eps = 1e-8;

int dsgn(double x) {
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
} up[30], down[30];

struct Line {
    Point a, b;
    Line() {}
    Line(Point _a, Point _b) : a(_a), b(_b) {}
} l[50];

double det(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double cross(Point o, Point a, Point b) {
    return det(a.x - o.x, a.y - o.y, b.x - o.x, b.y - o.y);
}

int segInter(Line a, Line b, Point &p) {
    int d1, d2;
    double s1, s2;
    d1 = dsgn(s1 = cross(a.a, a.b, b.a));
    d2 = dsgn(s2 = cross(a.a, a.b, b.b));

    if (d1 * d2 > 0)
        return -1;

    p.x = (s2 * b.a.x - s1 * b.b.x) / (s2 - s1);
    p.y = (s2 * b.a.y - s1 * b.b.y) / (s2 - s1);

    if (d1 * d2 == 0)
        return 0;
    return 1;
}

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF and n) {
        for (int i = 0; i != n; ++i) {
            scanf("%lf %lf", &up[i].x, &up[i].y);
            down[i].x = up[i].x, down[i].y = up[i].y - 1;
        }

        Point p1;
        double ans = -1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;
                Line l1 = Line(up[i], down[j]);

                int k = 0;
                while (k != n and segInter(l1, Line(up[k], down[k]), p1) >= 0)
                    k++;
                if (k == n)
                    ans = up[n-1].x;
                else if (k > 0) {
                    if (segInter(l1, Line(up[k-1], up[k]), p1) >= 0)
                        ans = max(ans, p1.x);
                    if (segInter(l1, Line(down[k-1], down[k]), p1) >= 0)
                        ans = max(ans, p1.x);
                }
            }
        }

        if (dsgn(ans - up[n-1].x) == 0)
            puts("Through all the pipe.");
        else
            printf("%.2f\n", ans);
    }
    return 0;
}


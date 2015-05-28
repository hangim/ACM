#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const double INF = 10000;
const double eps = 1e-8;

int sgn(double x) {
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}

int cmp(double a, double b) {
    return sgn(a - b);
}

struct Point {
    double x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

struct Line {
    Point s, t;
    Line() {}
    Line(Point _s, Point _t) : s(_s), t(_t) {}
};

double det(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}

double cross(Point o, Point a, Point b) {
    return det(a.x - o.x, a.y - o.y, b.x - o.x, b.y - o.y);
}

double area(Point a, Point b, Point c) {
    return fabs(cross(a, b, c)) / 2;
}

int intersect(Line a, Line b, Point &p) {
    int d1, d2, d3, d4;
    double s1, s2, s3, s4;
    d1 = sgn(s1 = cross(a.s, a.t, b.s));
    d2 = sgn(s2 = cross(a.s, a.t, b.t));
    d3 = sgn(s3 = cross(b.s, b.t, a.s));
    d4 = sgn(s4 = cross(b.s, b.t, a.t));
    
    if (d1 * d2 > 0 or d3 * d4 > 0)
        return -1; // 不相交

    p.x = (b.s.x * s2 - b.t.x * s1) / (s2 - s1);
    p.y = (b.s.y * s2 - b.t.y * s1) / (s2 - s1);

    if (d1 * d2 == 0 or d3 * d4 == 0)
        return 0; // 非规范相交

    return 1; // 规范相交
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        Line l1, l2;
        cin >> l1.s.x >> l1.s.y >> l1.t.x >> l1.t.y;
        cin >> l2.s.x >> l2.s.y >> l2.t.x >> l2.t.y;
        if (cmp(l1.s.y, l1.t.y) < 0)
            swap(l1.s, l1.t);
        if (cmp(l2.s.y, l2.t.y) < 0)
            swap(l2.s, l2.t);
        Point p1, p2, p3, p4;
        if (cmp(l1.s.y, l1.t.y) == 0 or cmp(l2.s.y, l2.t.y) == 0 // 平行x轴
            or intersect(l1, l2, p1) == -1 // 不相交
            or intersect(l1, Line(l2.s, Point(l2.s.x, INF)), p2) >= 0 // 遮挡
            or intersect(l2, Line(l1.s, Point(l1.s.x, INF)), p2) >= 0) {
            cout << "0.00" << endl;
            continue;
        }

        double ans;
        if (intersect(l1, Line(Point(-INF, l2.s.y), Point(INF, l2.s.y)), p3) >= 0) // 作l2.s的水平线
            ans = area(p1, p3, l2.s);
        else if (intersect(l2, Line(Point(-INF, l1.s.y), Point(INF, l1.s.y)), p4) >= 0) // 作l1.s的水平线
            ans = area(p1, p4, l1.s);
        cout << setprecision(2) << fixed << ans << endl;
    }
    return 0;
}


#include <iostream>

using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
} s, t;

int cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool f(int x1, int y1, int x2, int y2) {
    Point a(x1, y1);
    Point b(x2, y2);
    double d1 = cross(s, t, a) * cross(s, t, b);
    double d2 = cross(a, b, s) * cross(a, b, t);
    return (d1 <= 0 and d2 < 0) or (d1 < 0 and d2 <= 0);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int xleft, ytop, xright, ybottom;
        cin >> s.x >> s.y >> t.x >> t.y
            >> xleft >> ytop >> xright >> ybottom;
        if (xleft > xright)
            swap(xleft, xright);
        if (ytop < ybottom)
            swap(ytop, ybottom);

        if (   f(xleft, ytop, xright, ytop)
            or f(xleft, ytop, xleft, ybottom) 
            or f(xright, ytop, xright, ybottom) 
            or f(xleft, ybottom, xright, ybottom)
            or (xleft <= s.x and s.x <= xright and ybottom <= s.y and s.y <= ytop)
            or (xleft <= t.x and t.x <= xright and ybottom <= t.y and t.y <= ytop))
            cout << "T" << endl;
        else
            cout << "F" << endl;
    }
    return 0;
}


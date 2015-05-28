#include <iostream>
#include <cstdio>

using namespace std;

struct Point {
    double x, y;
};

struct Line {
    Point a, b;
} l[100000];

double cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool quick(Line &p, Line &q) {
    if (    min(p.a.x, p.b.x) <= max(q.a.x, q.b.x)
        and min(p.a.y, p.b.y) <= max(q.a.y, q.b.y)
        and min(q.a.x, q.b.x) <= max(p.a.x, p.b.x)
        and min(q.a.y, q.b.y) <= max(p.a.y, p.b.y)
        and cross(p.a, p.b, q.a) * cross(p.a, p.b, q.b) < 0
        and cross(q.a, q.b, p.a) * cross(q.a, q.b, p.b) < 0)
        return true;
    return false;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF and n) {
        for (int i = 1; i <= n; ++i)
            scanf("%lf %lf %lf %lf", &l[i].a.x, &l[i].a.y, &l[i].b.x, &l[i].b.y);
        printf("Top sticks:");
        bool flag = true;
        for (int i = 1; i < n; ++i) {
            int j;
            for (j = i + 1; j <= n; ++j)
                if (quick(l[i], l[j]))
                    break;
            if (j == n + 1)
                printf(" %d,", i);
        }
        printf(" %d.\n", n);
    }
    return 0;
}


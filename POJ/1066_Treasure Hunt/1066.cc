#include <iostream>
#include <cstdio>

using namespace std;

struct Point {
    double x, y;
} treasure;

struct Line {
    Point a, b;
} walls[40];

int n;

double cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x) * (b. y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int slove(Point &a, Point &b) {
    int ret = 0;
    for (int i = 0; i != n; ++i)
        if (cross(a, b, walls[i].a) * cross(a, b, walls[i].b) < 0
            and cross(walls[i].a, walls[i].b, a) * cross(walls[i].a, walls[i].b, b) < 0)
            ret++;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%lf %lf %lf %lf", &walls[i].a.x, &walls[i].a.y,
            &walls[i].b.x, &walls[i].b.y);
    scanf("%lf %lf", &treasure.x, &treasure.y);

    int ans = n == 0 ? 0 : 999;
    for (int i = 0; i != n; ++i) {
        ans = min(slove(treasure, walls[i].a), ans);
        ans = min(slove(treasure, walls[i].b), ans);
    }

    printf("Number of doors = %d\n", ans + 1);
    return 0;
}


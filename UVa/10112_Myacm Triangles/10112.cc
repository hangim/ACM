#include <iostream>

using namespace std;

typedef struct {
    int x;
    int y;
    char name;
} Point;

int area2(Point a, Point b, Point c) {
    int s2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return s2 > 0 ? s2 : -s2;
}

int inside(Point d, Point a, Point b, Point c) {
    return area2(d, a, b) + area2(d, a, c) + area2(d, b, c)
        == area2(a, b, c);
}

int main() {

    Point m[15];

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        int max_a, max_b, max_c, max_s2 = 0;
        for (int i = 0; i < n; i++)
            cin >> m[i].name >> m[i].x >> m[i].y;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int var = area2(m[i], m[j], m[k]);
                    if (var <= max_s2)
                        continue;

                    bool noInside = true;
                    for (int tmp = 0; noInside and tmp < n; tmp++) {
                        if (tmp == i or tmp == j or tmp == k)
                            continue;

                        if (inside(m[tmp], m[i], m[j], m[k])) {
                            noInside = false;
                        }
                    }

                    if (noInside) {
                        max_s2 = var;
                        max_a = i;
                        max_b = j;
                        max_c = k;
                    }
                }
            }
        }

        cout << m[max_a].name << m[max_b].name << m[max_c].name << endl;
    }

    return 0;
}

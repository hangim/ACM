#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int id, x, y;
} p[55];

int cross(Point &o, Point &a, Point &b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);    
}

double dist(Point &a, Point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i].id >> p[i].x >> p[i].y;
            if (i != 1 and p[i].y < p[1].y)
                swap(p[i], p[1]);
        }
        p[0] = p[1];
        p[0].x = 0;

        for (int i = 2; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int d = cross(p[i-1], p[j], p[i]);
                if (d > 0 or (d == 0 and dist(p[i-1], p[j]) < dist(p[i-1], p[i])))
                    swap(p[i], p[j]);
            }
        }

        cout << n;
        for (int i = 1; i <= n; ++i) {
            cout << " " << p[i].id;
        }
        cout << endl;
    }
    return 0;
}


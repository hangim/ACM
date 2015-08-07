#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    Point() = default;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (const Point &o) const {
        if (x == o.x)
            return y < o.y;
        return x < o.x;
    }
};

vector<Point> v;

int L, W, n, k;

int X(int x, int dir) {
    if (dir) {
        if ((x + k) / L % 2)
            return L - (x + k) % L;
        else
            return (x + k) % L;
    } else {
        if ((L - x + k) / L % 2)
            return (L - x + k) % L;
        else
            return L - (L - x + k) % L;
    }
}

int Y(int y, int dir) {
    if (dir) {
        if ((y + k) / W % 2)
            return W - (y + k) % W;
        else
            return (y + k) % W;
    } else {
        if ((W - y + k) / W % 2)
            return (W - y + k) % W;
        else
            return W - (W - y + k) % W;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        v.clear();
        scanf("%d %d %d %d", &L, &W, &n, &k);
        for (int i = 0; i < n; ++i) {
            int x, y;
            char s[10];
            scanf("%d %d %s", &x, &y, s);
            v.push_back(Point(X(x, s[1] == 'E'), Y(y, s[0] == 'N')));
        }
        sort(v.begin(), v.end());

        printf("Case %d:\n", cs);
        for (int i = 0; i < v.size(); ++i)
            printf("%d %d\n", v[i].x, v[i].y);

    }
    return 0;
}


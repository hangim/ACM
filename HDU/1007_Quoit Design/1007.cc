#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const double DINF = 1e9;

struct Point {
    double x, y;
};

Point pts[MAXN];
Point ptsTemp[MAXN];

bool cmpx(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool cmpy(const Point &a, const Point &b) {
    return a.y < b.y;
}

double dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double search(int l, int r) {
    if (l == r)
        return DINF;
    if (l + 1 == r)
        return dist(pts[l], pts[r]);
    if (l + 2 == r)
        return min(dist(pts[l], pts[l+1]), min(dist(pts[l], pts[r]),
            dist(pts[l+1], pts[r])));
    int mid = (l + r) / 2;
    double ans = min(search(l, mid), search(mid + 1, r));
    
    int k = 0;
    for (int i = l; i <= r; ++i)
        if (fabs(pts[i].x - pts[mid].x) <= ans)
            ptsTemp[k++] = pts[i];
    sort(ptsTemp, ptsTemp + k, cmpy);
    for (int i = 0; i < k; ++i) {
        for (int j = i + 1; j < k; ++j) {
            if (ptsTemp[j].y - ptsTemp[i].y >= ans)
                break;
            ans = min(ans, dist(ptsTemp[i], ptsTemp[j]));
        }
    }
    return ans;
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF and N) {
        for (int i = 0; i != N; ++i)
            scanf("%lf %lf", &pts[i].x, &pts[i].y);
        sort(pts, pts + N, cmpx);
        printf("%.2f\n", search(0, N - 1) * 0.5);
    }
    return 0;
}


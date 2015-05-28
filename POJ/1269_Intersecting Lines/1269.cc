#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
} P[5];

struct Vector {
    int x, y;
};

Vector operator - (Point a, Point b) {
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

int cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    cout << "INTERSECTING LINES OUTPUT" << endl;

    int n;
    cin >> n;
    while (n--) {
        for (int i = 1; i <= 4; ++i)
            cin >> P[i].x >> P[i].y;
        if (cross(P[2] - P[1], P[4] - P[3]) == 0) { // parallel
            if (cross(P[3] - P[1], P[2] - P[1]) == 0)
                cout << "LINE" << endl;
            else
                cout << "NONE" << endl;
            continue;
        }
        double k = 1.0 * cross(P[3] - P[1], P[2] - P[1]) / (cross(P[3] - P[1], P[2] - P[1]) + cross(P[2] - P[1], P[4] - P[1]));
        double x = P[3].x + (P[4].x - P[3].x) * k;
        double y = P[3].y + (P[4].y - P[3].y) * k;
        cout << "POINT " << setprecision(2) << fixed << x << " " << y << endl;

    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
char M[10][10][11];
int D[10][10][10];

struct Point {
    int x, y, z;
    Point(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator == (const Point &o) const {
        return x == o.x and y == o.y and z == o.z;
    }
};

bool inMatrix(int x, int y, int z) {
    return x >= 0 and x < n and y >= 0 and y < n and z >= 0 and z < n;
}

int bfs(Point start_point, Point end_point) {
    static int dir[6][3] = {1, 0, 0, 0, 1, 0, -1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1};
    memset(D, -1, sizeof(D));

    queue<Point> q;
    q.push(start_point);
    D[start_point.z][start_point.x][start_point.y] = 0;

    while (not q.empty()) {
        Point point = q.front();
        q.pop();

        int x = point.x, y = point.y, z = point.z;
        if (point == end_point)
            return D[z][x][y];

        for (int i = 0; i != 6; ++i) {
            int _x = x + dir[i][0];
            int _y = y + dir[i][1];
            int _z = z + dir[i][2];

            if (inMatrix(_x, _y, _z) and M[_z][_x][_y] == 'O' and D[_z][_x][_y] == -1) {
                q.push(Point(_x, _y, _z));
                D[_z][_x][_y] = D[z][x][y] + 1;
            }
        }
    }

    return -1;
}

int main() {
    string str;
    while (cin >> str >> n) {
        for (int z = 0; z != n; ++z) {
            for (int x = 0; x != n; ++x) {
                cin >> M[z][x];
            }
        }

        int s_x, s_y, s_z, e_x, e_y, e_z;
        cin >> s_x >> s_y >> s_z >> e_x >> e_y >> e_z;
        cin >> str;

        int ans = bfs(Point(s_x, s_y, s_z), Point(e_x, e_y, e_z));
        if (ans == -1)
            cout << "NO ROUTE" << endl;
        else
            cout << n << " " << ans << endl;
    }
    return 0;
}


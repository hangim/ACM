#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

struct Drop {
    int x, y, d;
    int live;

    Drop() {}

    Drop(int _x, int _y, int _d) : x(_x), y(_y), d(_d), live(1) {}

    void move() {
        x += dir[d][0];
        y += dir[d][1];
    }
};

struct Waterdrop {
    int x, y, size, time;
} water[110];

vector<Drop> drops;

int mm[110][110];

int main() {
    int r, c, n, T;
    while (scanf("%d %d %d %d", &r, &c, &n, &T) != EOF) {
        drops.clear();
        memset(mm, 0, sizeof(mm));
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &water[i].x, &water[i].y, &water[i].size);
            mm[water[i].x][water[i].y] = i;
            water[i].time = 0;
        }
        int _xx, _yy;
        scanf("%d %d", &_xx, &_yy);
        for (int i = 0; i < 4; ++i)
            drops.push_back(Drop(_xx, _yy, i));
        
        for (int tt = 1; tt <= T; ++tt) {
            for (int i = 0; i < (int)drops.size(); ++i) {
                if (drops[i].live == 0) continue;
                drops[i].move(); // Move
                int x = drops[i].x, y = drops[i].y;
                if (x < 1 or x > r or y < 1 or y > c) {
                    drops[i].live = 0;
                    continue;
                }
                
                if (mm[x][y] == 0 or water[mm[x][y]].time != 0) continue;
                water[mm[x][y]].size += 1; // size increases
                drops[i].live = 0;
            }

            for (int i = 1; i <= n; ++i) {
                if (water[i].time == 0 and water[i].size > 4) { // Boom !!!
                    //cout << tt << " : " << i << " boom " << endl;
                    water[i].time = tt;
                    for (int j = 0; j < 4; ++j)
                        drops.push_back(Drop(water[i].x, water[i].y, j));
                }
            }
        }

        for (int i = 1; i <= n; ++i)
            printf("%d %d\n", water[i].size > 4 ? 0 : 1, water[i].time ? water[i].time : water[i].size);
    }
    return 0;
}


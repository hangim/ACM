#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

unsigned long long hash(int x, int y) {
    // x in [0, 8), y in [0, 8)
    return (1uLL << (x * 8 + y));
}

bool inMap(int x, int y) {
    return x >= 0 and x < 8 and y >= 0 and y < 8;
}

struct Node {
    unsigned long long stage;
    int step;
};

bool bfs(unsigned long long start, set<unsigned long long> &s1, set<unsigned long long> &s2) {
    static int dir1[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    static int dir2[4][2] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};

    queue<struct Node> q;
    struct Node now = {start, 0};
    q.push(now);

    while (not q.empty()) {
        now = q.front();
        q.pop();
        if (now.step == 4)
            continue;

        for (int k = 0; k < 64; k++) {
            // 遍历查找4个棋子
            if ((now.stage & (1uLL << k)) == 0uLL)
                continue;

            int x = k / 8;
            int y = k % 8;

            for (int i = 0; i < 4; i++) {
                int x1 = x + dir1[i][0];
                int y1 = y + dir1[i][1];
                int x2 = x + dir2[i][0];
                int y2 = y + dir2[i][1];
               
                struct Node next;
                next.step = now.step + 1;
                
                if (not inMap(x1, y1))
                    continue;
                if ((now.stage & hash(x1, y1)) == 0) { // 搜索一步
                    next.stage = now.stage & (~hash(x, y));
                    next.stage |= hash(x1, y1);

                    if (s1.find(next.stage) == s1.end()) {
                        if (s2.find(next.stage) != s2.end())
                            return true;
                        s1.insert(next.stage);
                        q.push(next);
                    }
                } else if (inMap(x2, y2) and (now.stage & hash(x2, y2)) == 0) { // 搜索两步
                    next.stage = now.stage & (~hash(x, y));
                    next.stage |= hash(x2, y2);

                    if (s1.find(next.stage) == s1.end()) {
                        if (s2.find(next.stage) != s2.end())
                            return true;
                        s1.insert(next.stage);
                        q.push(next);
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        unsigned long long start = 0;
        unsigned long long end = 0;

        start |= hash(x - 1, y - 1);
        for (int i = 0; i < 3; i++) {
            cin >> x >> y;
            start |= hash(x - 1, y - 1);
        }

        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            end |= hash(x - 1, y - 1);
        }

        // 记录搜索结果
        set<unsigned long long> s1;
        set<unsigned long long> s2;
        s1.insert(start);
        s2.insert(end);


        // 双向广搜
        if (start == end or bfs(start, s1, s2) or bfs(end, s2, s1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}


#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node {
    int x, y;

    bool operator < (const Node &o) const {
        if (x != o.x)
            return x > o.x;
        return y > o.y;
    }
};

Node mac[100001];
Node task[100001];
int c[101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++)
            cin >> mac[i].x >> mac[i].y;
        for (int i = 0; i < m; i++)
            cin >> task[i].x >> task[i].y;
        sort(mac, mac + n);
        sort(task, task + m);

        memset(c, 0, sizeof(c));
        int num = 0;
        long long money = 0;
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n and mac[j].x >= task[i].x) {
                c[mac[j].y]++;
                j++;
            }

            for (int k = task[i].y; k <= 100; k++) {
                if (c[k]) {
                    c[k]--;
                    num++;
                    money += 500 * task[i].x + 2 * task[i].y;
                    break;
                }
            }
        }
        cout << num << " " << money << endl;
    }

    return 0;
}


#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

struct Node {
    int u;
    double maxDis;

    bool operator < (const Node &o) const {
        return maxDis > o.maxDis;
    }
};

struct Point {
    double x, y;
} P[210];

int vis[210];

double bfs(int n) {
    for (int i = 1; i <= n; ++i)
        vis[i] = false;

    priority_queue<Node> q;

    Node node;
    node.u = 1;
    node.maxDis = 0;
    q.push(node);

    while (true) {
        node = q.top();
        q.pop();
        if (node.u == 2)
            return node.maxDis;
        vis[node.u] = true;
        for (int i = 1; i <= n; ++i) {
            if (vis[i])
                continue;
            double d = hypot(P[node.u].x - P[i].x, P[node.u].y - P[i].y);
            Node next;
            next.u = i;
            next.maxDis = max(node.maxDis, d);
            q.push(next);
        }
    }
}

int main() {
    int n;
    int k = 1;
    while (cin >> n and n) {
        for (int i = 1; i <= n; ++i)
            cin >> P[i].x >> P[i].y;
        if (k != 1)
            cout << endl;
        cout << "Scenario #" << k++ << endl << "Frog Distance = "
             << setprecision(3) << fixed << bfs(n) << endl;
    }

    return 0;
}


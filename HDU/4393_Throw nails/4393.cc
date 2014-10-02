#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int id;
    int f;

    Node(int _id, int _f) : id(_id), f(_f) {}
    bool operator < (const Node &o) const {
        if (f != o.f)
            return f < o.f;
        return id > o.id;
    }
};

priority_queue<Node> q[101];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    int k = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int f, s;
            cin >> f >> s;
            q[s].push(Node(i, f));
        }

        cout << "Case #" << k++ << ":" << endl;

        for (int t = 0; t < n; t++) {
            int id = 50000;
            int index = 0;
            int d = 0;
            for (int i = 1; i <= 100; i++) {
                if (q[i].empty())
                    continue;
                int var = i * t + q[i].top().f;
                if (var > d or var == d and q[i].top().id < id) {
                    d = var;
                    index = i;
                    id = q[i].top().id;
                }
            }

            cout << q[index].top().id;
            q[index].pop();
            if (t != n-1)
                cout << " ";
            else
                cout << endl;
        }
    }

    return 0;
}


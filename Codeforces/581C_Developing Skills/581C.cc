#include <bits/stdc++.h>

using namespace std;

struct Node {
    int a, rem;
    Node() = default;
    Node(int a) {
        this->a = a;
        this->rem = 10 - a % 10;
    }
    bool operator < (const Node &o) const {
        return rem > o.rem;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, score = 0;
    priority_queue<Node> q;
    cin >> n >> k;
    while (n--) {
        int a;
        cin >> a;
        score += a / 10;
        if (a != 100)
            q.push(Node(a));
    }

    while (not q.empty()) {
        Node x = q.top();
        q.pop();
//        cout << "debug " << x.rem << endl;
        if (x.rem <= k) {
            score++;
            k -= x.rem;
            if (x.a + x.rem != 100)
                q.push(Node(x.a + x.rem));
        } else {
            break;
        }
    }

    cout << score << endl;

    return 0;
}


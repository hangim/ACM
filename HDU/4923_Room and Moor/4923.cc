#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

int A[100000];

struct Node {
    int s, t;
    double x;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> A[i];

        int from = 0, end = n-1;
        while (A[from] == 0 and from <= n-1)
            from++;
        while (A[end] == 1 and end >= 0)
            end--;


        queue<Node> q;
        int i = from;
        while (i <= end) {
            Node node;
            node.s = node.t = 0;
            while (A[i] == 1) {
                node.s++;
                i++;
            }
            while (A[i] == 0 and i <= end) {
                node.t++;
                i++;
            }
            node.x = 1.0 * node.s / (node.s + node.t);
            q.push(node);
        }
            
        stack<Node> s;
        while (not q.empty()) {
            Node node = q.front();
            q.pop();

            while (not s.empty() and node.x < s.top().x) {
                node.s += s.top().s;
                node.t += s.top().t;
                node.x = 1.0 * node.s / (node.s + node.t);
                s.pop();
            }
            s.push(node);
        }

        double ans = 0;
        while (not s.empty()) {
            Node node = s.top();
            s.pop();
            ans += node.s * pow(1 - node.x, 2)
                 + node.t * pow(node.x, 2);
        }

        cout << setprecision(6) << fixed << ans << endl;
    }

    return 0;
}


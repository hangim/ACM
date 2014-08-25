#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int e, k;
    double rank;

    bool operator < (const Node &o) const {
        return rank > o.rank;
    }
} node[100000];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> node[i].e;
    for (int i = 0; i < n; i++) {
        cin >> node[i].k;
        node[i].rank = 1.0 * node[i].k / node[i].e;
    }
    sort(node, node + n);

    long long ans = 0;
    long long time = 0;
    for (int i = 0; i < n; i++) {
        time += node[i].e;
        ans += node[i].k * time;
    }
    cout << ans << endl;

    return 0;
}



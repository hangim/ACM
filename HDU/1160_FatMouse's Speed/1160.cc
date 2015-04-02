#include <bits/stdc++.h>

using namespace std;

struct Node {
    int index, size, speed;
    Node(int _index, int _size, int _speed) :
        index(_index), size(_size), speed(_speed) {}
    bool operator < (const Node &o) const {
        return size < o.size;
    }
};

vector<Node> v;
int dp[1010], pre[1010];

void output(int x) {
    if (pre[x] != -1)
        output(pre[x]);
    cout << v[x].index << endl;
}

int main() {
    int k = 1;
    int size, speed;
    while (cin >> size >> speed)
        v.push_back(Node(k++, size, speed));
    sort(v.begin(), v.end());

    int ans = 0, x = 0;
    for (int i = 0; i != v.size(); ++i) {
        dp[i] = 1;
        pre[i] = -1;
        for (int j = 0; j != i; ++j) {
            if (v[j].size < v[i].size and v[j].speed > v[i].speed and dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            } 
        }
        if (dp[i] > ans) {
            ans = dp[i];
            x = i;
        }
    }

    cout << ans << endl;
    output(x);
    return 0;
}


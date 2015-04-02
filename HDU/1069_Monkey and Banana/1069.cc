#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, z;
    Node(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    bool operator < (const Node &o) const {
        if (x > o.x)
            return true;
        if (x == o.x and y > o.y)
            return true;
        return false;
    }
};

vector<Node> v;
int dp[100];

int main() {
    int n;
    int k = 1;
    while (cin >> n and n) {
        v.clear();
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i != n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            v.push_back(Node(max(x, y), min(x, y), z));
            v.push_back(Node(max(z, y), min(z, y), x));
            v.push_back(Node(max(x, z), min(x, z), y));
        }
        sort(v.begin(), v.end());
        
        int ans = 0;
        for (int i = 0; i != v.size(); ++i)
            dp[i] = v[i].z;
        for (int i = 1; i != v.size(); ++i) {
            for (int j = 0; j != i; ++j) {
                if (v[j].x > v[i].x and v[j].y > v[i].y)
                    dp[i] = max(dp[i], dp[j] + v[i].z);
            }
            ans = max(ans, dp[i]);
        }
        
        cout << "Case " << k++ << ": maximum height = " << ans << endl;
    }

    return 0;
}


#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int start, end, efficiency;
    bool operator < (const Node &o) const {
        return start < o.start;
    }
} milk[1001];

int dp[1001];

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i != m; ++i)
        cin >> milk[i].start >> milk[i].end >> milk[i].efficiency;
    sort(milk, milk + m);

    int ans = 0;
    for (int i = 0; i != m; ++i) {
        dp[i] = milk[i].efficiency;
        for (int j = 0; j != m; ++j) {
            if (milk[j].end + r <= milk[i].start)
                dp[i] = max(dp[i], dp[j] + milk[i].efficiency);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int l, r;
    
    Node(int _l, int _r) {
        l = _l;
        r = _r;
    }

    bool operator < (const Node &o) const {
        return r < o.r;
    }
};

bool match(const Node &a, const Node &b, const int k) {
    if (a.l >= b.l + k and a.r <= b.r + k)
        return true;
    if (a.l <= b.l + k and b.r + k <= a.r)
        return true;
    // if (a.r >= b.l + 1 + k and a.r <= b.r + k)
    //     return true;
    // if (a.l + 1 <= b.r + k and a.l >= b.l + k)
    //     return true;
    if (a.r >= b.l + k and a.r <= b.r + k)
        return true;
    if (a.l <= b.r + k and a.l >= b.l + k)
        return true;
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<Node> v1, v2;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        v1.push_back(Node(a, b));
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        v2.push_back(Node(a, b));
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int ans = 0;
    for (int k = l; k <= r; k++) {
        for (int i = 0, j = 0; i != v1.size() and j != v2.size(); ) {
            if (match(v1[i], v2[j], k)) {
                // cout << ends << k << endl;
                ans++;
                break;
            }
            if (v1[i].l > v2[j].r + k)
                j++;
            else
                i++;
        }
    }
    cout << ans << endl;

    return 0;
}


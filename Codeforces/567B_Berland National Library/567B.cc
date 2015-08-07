#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
} node[110];

int cnt[110];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s >> node[i].y;
        if (s == "+")
            node[i].x = 1;
        else
            node[i].x = -1;
    }
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (node[i].x == 1) {
            s.insert(node[i].y);
            cnt[i]++;
            cnt[i + 1] = cnt[i];
        } else {
            if (s.find(node[i].y) == s.end()) {
                cnt[i + 1] = cnt[i];
                for (int j = 0; j <= i; ++j)
                    ++cnt[j];
            } else {
                cnt[i + 1] = cnt[i] - 1;
                s.erase(s.find(node[i].y));
            }
        }
    }
    int ans = *max_element(cnt, cnt + n);
    cout << ans  << endl;
    return 0;
}


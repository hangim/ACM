#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    Node() {
        x = y = 0;
    }

    bool operator < (const Node &o) const {
        return y > o.y;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n;
        cin >> n;
        vector<Node> v(101);
        for (int i = 0; i <= 100; i++)
            v[i].x = i;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a > 100)
                a = 200 - a;
            v[a].y++;
        }

        sort(v.begin(), v.end());

        cout << "Case #" << k << ":" << endl;

        int i = 0;
        for (i = 0; i < v.size(); ++i) {
//            cout << v[i].x << " " << v[i].y << endl;
            if (v[i].y != v[0].y)
                break;
        }

        if ((i == v.size() or v[i].y == 0) and v[0].x != v[i-1].x)
            cout << "Bad Mushroom" << endl;
        else {
            vector<int> v2;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].y != v[0].y)
                    break;
                v2.push_back(v[j].x);
            }

            sort(v2.begin(), v2.end());
            
            for (int j = 0; j < v2.size(); j++) {
                cout << 10000 - (100 - v2[j]) * (100 - v2[j]);
                if (j != v2.size() - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
    }

    return 0;
}


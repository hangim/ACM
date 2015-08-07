#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    int price;

    bool operator < (const Node &o) const {
        return price < o.price;
    }
};

vector<Node> v;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, M, D;
        cin >> S >> M >> D;

        string name;
        int price;
        int index;

        int ans = 0;
        string ansd[3];

        v.clear();
        for (int i = 0; i != S; ++i) {
            cin >> name >> price;
            Node node;
            node.name = name;
            node.price = price;
            v.push_back(node);
        }
        sort(v.begin(), v.end());
        index = S / 2;
        ans += v[index].price;
        ansd[0] = v[index].name;

        v.clear();
        for (int i = 0; i != M; ++i) {
            cin >> name >> price;
            Node node;
            node.name = name;
            node.price = price;
            v.push_back(node);
        }
        sort(v.begin(), v.end());
        index = M / 2;
        ans += v[index].price;
        ansd[1] = v[index].name;

        v.clear();
        for (int i = 0; i != D; ++i) {
            cin >> name >> price;
            Node node;
            node.name = name;
            node.price = price;
            v.push_back(node);
        }
        sort(v.begin(), v.end());
        index = D / 2;
        ans += v[index].price;
        ansd[2] = v[index].name;

        cout << ans << " " << ansd[0] << " " << ansd[1] << " "
             << ansd[2] << endl;
    }
    return 0;
}


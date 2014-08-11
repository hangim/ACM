#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int root[1001];

struct Edge {
    int from;
    int to;
    int length;

    Edge(int from, int to, int length) {
        this->from = from;
        this->to = to;
        this->length = length;
    }

    bool operator < (const struct Edge &o) const {
        return this->length < o.length;
    }
};

int findRoot(int x) {
    int t = root[x];
    while (t != root[t])
        t = root[t];
    return t;
}

void merge(int a, int b) {
    int x = findRoot(a);
    int y = findRoot(b);
    if (x != y)
        root[y] = x;
}

int main() {

    // init root[i] to itself
    for (int i = 0; i < 1001; i++)
        root[i] = i;

    // input edge and sort them by length
    int n, m;
    cin >> n >> m;
    vector<struct Edge> v;

    for (int i = 0; i < m; i++) {
        int from, to, length;
        cin >> from >> to >> length;
        v.push_back(*new struct Edge(from, to, length));
    }

    sort(v.begin(), v.end());

    // kruskal
    int maxLength = 0;
    vector<struct Edge> ans;
    for (int i = 0; i < m; i++) {
        if (findRoot(v[i].from) != findRoot(v[i].to)) {
            maxLength = max(maxLength, v[i].length);
            merge(v[i].from, v[i].to);
            ans.push_back(v[i]);
        }
    }
    
    // output
    cout << maxLength << endl;
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << ans[i].from << " " << ans[i].to << endl;

    return 0;
}


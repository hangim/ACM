#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int z, i, m, l;
    int index = 1;
    while (cin >> z >> i >> m >> l) {
        if (z == 0 and i == 0 and m == 0 and l == 0)
            break;

        set<int> s;
        vector<int> v;
        int cnt = 0;
        while (s.find(l) == s.end()) {
            s.insert(l);
            v.push_back(l);
            l = (z * l + i) % m;
            // cout << l << endl;
            cnt++;
        }

        cout << "Case " << index++ << ": " 
             << cnt - (find(v.begin(), v.end(), l) - v.begin()) << endl;
    }

    return 0;
}

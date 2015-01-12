#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> used, old;
    map<string, string> m;

    int n;
    cin >> n;
    while (n--) {
        string s1, s2;
        cin >> s1 >> s2;
        m[s1] = s2;
        if (used.find(s1) == used.end()) {
            old.insert(s1);
        }
        used.insert(s1);
        used.insert(s2);
    }

    cout << old.size() << endl;
    for (auto it : old) {
        cout << it << " ";
        string s = m[it];
        while (m.find(s) != m.end())
            s = m[s];
        cout << s << endl;
    }

    return 0;
}

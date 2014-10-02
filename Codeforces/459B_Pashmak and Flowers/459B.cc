#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
        long long var;
        cin >> var;
        if (m.find(var) == m.end())
            m[var] = 1;
        else
            m[var]++;
    }

    cout << m.rbegin()->first - m.begin()->first << " ";
    if (m.size() == 1)
        cout << m.begin()->second * (m.begin()->second - 1) / 2 << endl;
    else
        cout << m.rbegin()->second * m.begin()->second << endl;

    return 0;
}


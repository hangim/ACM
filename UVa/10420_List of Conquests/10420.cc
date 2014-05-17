#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    map<string, int> m;
    map<string, int>::iterator it;

    int n;
    cin >> n;

    string s, spare;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i != n-1)
            getline(cin, spare);

        if (m.find(s) != m.end())
            m[s]++;
        else
            m[s] = 1;
    }

    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}

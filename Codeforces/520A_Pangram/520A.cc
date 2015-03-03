#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    set<char> s;
    for (auto c : str)
        s.insert(c);

    if (s.size() == 26)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        int pos;
        string str;
        cin >> pos >> str;
        cout << k << " ";
        for (int i = 0; i != str.length(); ++i) {
            if (i + 1 != pos)
                cout << str[i];
        }
        cout << endl;
    }
    return 0;
}


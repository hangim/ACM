#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;

bool add(int x) {
    for (char c = s[x] + 1; c < 'a' + k; c++) {
        if (x > 1 and c == s[x-2])
            continue;
        if (x > 0 and c == s[x-1])
            continue;
        s[x] = c;
        return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    cin >> s;

    int p;
    for (p = n-1; p >= 0; p--) {
        if (add(p))
            break;
    }
    if (p == -1) {
        cout << "NO" << endl;
        return 0;
    }

    for (p = p + 1; p < n; p++) {
        s[p] = 'a' - 1;
        add(p);
    }
    cout << s << endl;

    return 0;
}


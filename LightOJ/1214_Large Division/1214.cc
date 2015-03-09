#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; ++k) {
        long long a, b, rem = 0;
    
        string str;
        cin >> str >> b;
        if (str[0] == '-')
            str.erase(str.begin());
        if (b < 0)
            b = -b;

        for (int i = 0; i != str.length(); ++i)
            rem = (rem * 10 + str[i] - '0') % b;

        cout << "Case " << k << ": "
             << (rem == 0 ? "divisible" : "not divisible") << endl;
    }

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        long long n;
        cin >> n;
        cout << "Case " << cs << ": " << n - (int)sqrt(n) - (int)sqrt(n / 2) << endl;
    }
    return 0;
}


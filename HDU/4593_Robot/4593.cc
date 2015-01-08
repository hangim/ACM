#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    int a[1001]; 

    while (cin >> n) {
        memset(a, 0, sizeof(a));
        int var, ans;
        for (int i = 0; i < n + 1; ++i) {
            cin >> var;
            if (a[var])
                ans = var;
            a[var] = 1;
        }
        cout << ans << endl;
    }

    return 0;
}


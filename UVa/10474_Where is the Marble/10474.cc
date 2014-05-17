#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n, q;
    int k = 1;
    while (cin >> n >> q) {
        if (n == 0 and q == 0)
            break;
    
        cout << "CASE# " << k++ << ":" << endl;

        int *num = new int[n];
        for (int i = 0; i < n; i++)
            cin >> num[i];
    
        sort(num, num + n);

        for (int i = 0; i < q; i++) {
            int var;
            cin >> var;
            int l = 0, r = n - 1, m;
            while (l <= r) {
                m = l + (r - l) / 2;
                if (num[m] == var) {
                    while (m > 0 and num[m-1] == var)
                        m--;
                    cout << var << " found at " << m + 1 << endl;
                    break;
                }
                if (num[m] < var)
                    l = m + 1;
                else
                    r = m - 1;
            }

            if (l > r)
                cout << var << " not found" << endl;
        }
    
    }

    return 0;
}

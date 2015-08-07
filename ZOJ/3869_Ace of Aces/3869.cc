#include <bits/stdc++.h>

using namespace std;

int A[1010];

int main () {
    int T;
    cin >> T;
    while (T--) {
        memset(A, 0, sizeof(A));
        int n;
        cin >> n;
        for (int i = 0; i != n; ++i) {
            int x;
            cin >> x;
            A[x] += 1;
        }

        int index = 0;
        bool flag = true;
        for (int i = 1; i <= 1000; ++i) {
            if (A[i] > A[index]) {
                index = i;
                flag = true;
            } else if (A[i] == A[index]) {
                flag = false;
            }
        }

        if (flag)
            cout << index << endl;
        else
            cout << "Nobody" << endl;
    }

    return 0;
}

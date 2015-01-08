#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        bool flag = true;

        while (flag) {
            sort(v.begin(), v.end());
            bool flag2 = true;
            for (int i = 0; i < n; ++i) {
                if (v[i] > i + 1)
                    flag = false;
                if (v[i] < i + 1) {
                    v[i] += k;
                    flag2 =false;
                    break;
                }
            }
            if (flag2)
                break;
        }

        if (flag)
            cout << "Jerry" << endl;
        else
            cout << "Tom" << endl;
    }

    return 0;
}


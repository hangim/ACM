#include <iostream>
#include <cstring>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    int times[201];

    int t;
    cin >> t;
    while (t--) {
        memset(times, 0, sizeof(times));
        
        int n;
        cin >> n;
        while (n--) {
            int from, to;
            cin >> from >> to;
            from = (from + 1) / 2;
            to = (to + 1) / 2;

            if (from >= to) {
                int tmp = from;
                from = to;
                to = tmp;
            }

            for (int i = from; i <= to; i++)
                times[i]++;
        }

        int maxn = 1;
        for (int i = 0; i < 201; i++)
            maxn = maxn > times[i] ? maxn : times[i];

        cout << maxn * 10 << endl;
    }

    return 0;
}


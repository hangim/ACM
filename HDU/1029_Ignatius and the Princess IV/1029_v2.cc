#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int nTimes = 0, num, ans;
        for (int i = 0; i != n; ++i) {
            scanf("%d", &num);
            if (nTimes == 0)
                ans = num;
            if (ans == num)
                ++nTimes;
            else
                --nTimes;
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010050;
bool vis[maxn + 10];
int num[10010];

void init_pri() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not vis[i]) {
            for (int j = i * i; j <= maxn; j += i)
                vis[j] = true;
        }
    num[0] = 1;
    for (int i = 1; i <= 10000; i++)
        num[i] = num[i-1] + not vis[i * i + i + 41];
}

int main() {
    init_pri();
    int a, b;
    while (cin >> a >> b) {
        cout << setprecision(2) << fixed
             << 100.0 * (num[b] - (a == 0 ? 0 : num[a-1])) / (b - a + 1) + 1e-6 << endl;
    }
    return 0;
}


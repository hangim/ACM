#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)64;
bool vis[maxn + 10];
int e[64 + 10], cnt = 0;
 
void init() {
    for (int i = 2; i * i <= maxn; ++i)
        if (not vis[i]) {
            for (int j = i * i; j <= maxn; j += i)
                vis[j] = true;
        }
    for (int i = 4; i <= maxn; ++i)
        if (vis[i])
            e[cnt++] = i;
}

unsigned long long quick_pow(unsigned long long x, int n) {
    unsigned long long c = 1;
    while (n) {
        if (n & 1)
            c = c * x;
        x = x * x;
        n >>= 1;
    }
    return c;
}

set<unsigned long long> s;

int main() {
    init();
    s.insert(1);
    for (int i = 2; i <= 65536; ++i) {
        int x = floor(log(pow(2.0, 64)-1) / log(i));
        for (int j = 0; j < cnt and e[j] <= x; ++j)
            s.insert(quick_pow(i, e[j]));
    }
    s.erase(s.begin());
    for (set<unsigned long long>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
int n, k, a;
int x[maxn + 10];


bool ok(int med) {
    vector<int> v(x, x + med);
    sort(v.begin(), v.end());

    int cnt = v[0] / (a + 1);
    for (int i = 0; i < med - 1; ++i)
        cnt += (v[i+1] - v[i]) / (a + 1);
    cnt += (n + 1 - v[med - 1]) / (a + 1);

    return cnt < k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k >> a;
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> x[i];

    int low = 0, high = m;
    while (high - low > 1) {
        int med = (low + high) / 2;
        if (ok(med))
            high = med;
        else
            low = med;
    }

    if (high == m and not ok(high))
        cout << -1 << endl;
    else
        cout << high << endl;
    
    return 0;
}


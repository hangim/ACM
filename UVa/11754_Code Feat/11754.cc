#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

void extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        extended_gcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

/*
 * ans % m[0] = a[0]
 * ans % m[k] = a[k]
 * ans % m[n-1] = a[n-1]
 */
long long CRT(long long *a, long long *m, int n) {
    long long M = 1, x, y, ans = 0;
    for (int i = 0; i < n; ++i)
        M *= m[i];
    for (int i = 0; i < n; ++i) {
        long long w = M / m[i];
        extended_gcd(w, m[i], x, y);
        ans = (ans + a[i] * w * x) % M;
    }
    return (ans + M) % M;
}

long long a[10], m[10];
int c, s;
vector<int> v[10];
set<int> ss[10];
set<long long> ans;

void dfs(int x) {
    if (x == c) {
        long long val = CRT(a, m, c);
        ans.insert(val);
        return;
    }
    for (int i = 0; i < v[x].size(); ++i) {
        a[x] = v[x][i];
        dfs(x + 1);
    }
}

void slove() {
    int base = 0;
    for (int i = 0; i < c; ++i) {
        if (v[base].size() * m[i] > v[i].size() * m[base])
            base = i;
    }
    for (int ratio = 0; ans.size() < s + 1; ratio++) {
        for (int j = 0; j < v[base].size(); ++j) {
            long long val = ratio * m[base] + v[base][j];
            bool flag = true;
            for (int k = 0; k < c; ++k) {
                if (ss[k].find(val % m[k]) == ss[k].end()) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans.insert(val);
        }
    }
}

int main() {
    while (cin >> c >> s and c + s) {
        for (int i = 0; i < 10; ++i) {
            v[i].clear();
            ss[i].clear();
        }
        ans.clear();

        long long total = 1;
        long long M = 1;
        for (int i = 0; i < c; ++i) {
            int k, y;
            cin >> m[i] >> k;
            M *= m[i];
            total *= k;
            while (k--) {
                cin >> y;
                v[i].push_back(y);
                sort(v[i].begin(), v[i].end());
                ss[i].insert(y);
            }
        }
       
        if (total >= 10000) {
            slove();
        } else {
            dfs(0);
        }

        while (s--) {
            if (*ans.begin() != 0) {
                cout << *ans.begin() << endl;
            } else {
                s++;
            }
            ans.insert(*ans.begin() + M);
            ans.erase(ans.begin());
        }
        cout << endl;
    }
    return 0;
}


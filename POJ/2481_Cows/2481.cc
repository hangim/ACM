#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int tree[100001];
int cnt[100000];

struct Cow {
    int id;
    int s, e;
    
    bool operator < (const Cow &o) const {
        // 按照 e 降序排列
        // e 相等时, 按s升序排列
        if (this->e != o.e)
            return this->e > o.e;
        return this->s < o.s;
    }

    bool operator == (const Cow &o) const {
        return this->e == o.e and this->s == o.s;
    }
} cows[100000];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int val) {
    while (x <= 100001) {
        tree[x] += val;
        x += lowbit(x);
    }
}

int sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n and n) {
        for (int i = 0; i < n; i++) {
            cows[i].id = i;
            cin >> cows[i].s >> cows[i].e;
            cows[i].s++;
            cows[i].e++;
        }
        sort(cows, cows + n);

        memset(tree, 0, sizeof(tree));
        memset(cnt, 0, sizeof(cnt));
        
        cnt[cows[0].id] = 0;
        update(cows[0].s, 1);

        for (int i = 1; i < n; i++) {
            if (cows[i] == cows[i-1])
                cnt[cows[i].id] = cnt[cows[i-1].id];
            else
                cnt[cows[i].id] = sum(cows[i].s);
            update(cows[i].s, 1);
        }

        for (int i = 0; i < n; i++)
            cout << cnt[i] << " ";
        cout << endl;
    }

    return 0;
}


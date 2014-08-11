#include <iostream>

using namespace std;

const int INF = 1 << 20;
int n, c1, c2;
int w[10];

int isOneTime(int x) {
    int sum = 0;
    int a[10], m = 0;

    for (int i = 0; i < n; i++) { // 遍历 x 包含的物品,记录到 a[m] 中
        if (x & (1<<i)) {
            sum += w[i];
            a[m++] = i;
        }
    }

    for (int i = 0; i < (1<<m); i++) { // 遍历 x 的子集
            int s1 = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1<<j)) {
                    s1 += w[a[j]];
                }
            }
            int s2 = sum - s1;
            if (s1 <= c1 and s2 <= c2 or s2 <= c1 and s1 <= c2)
                return true;
    }

    return false;
}

int dp() {
    static int m[1024];
    for (int i = 0; i < (1<<n); i++)
        m[i] = INF;

    m[0] = 0;
    for (int i = 1; i < (1<<n); i++) {
        if (isOneTime(i)) { // 枚举每次可以拉走的集合
            for (int j = i; j < (1<<n); j++) { // 枚举可以更新的集合
                if ((i & j) == i) { // j 包含 i
                    m[j] = min(m[j], m[i^j] + 1);
                }
            }
        }
    }

    return m[(1<<n)-1];
}

int main() {
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> n >> c1 >> c2;
        for (int i = 0; i < n; i++)
            cin >> w[i];
        cout << "Scenario #" << k << ":" << endl;
        cout << dp() << endl << endl;
    }

    return 0;
}


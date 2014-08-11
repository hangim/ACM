#include <iostream>

using namespace std;

int n;
int max_dep;
int num[20];

bool dfs(int cnt, int x) {
    // cnt 当前搜索深度
    // x 上一次搜索后最大的数
    if (num[cnt] == n) 
        return true;

    if (cnt == max_dep) // 搜索达到最大层数
        return false;

    x = max(x, num[cnt]);
    if (x * (1 << (max_dep - cnt)) < n) // 剪枝
        return false;

    for (int i = 0; i <= cnt; i++) {
        num[cnt+1] = num[i] + num[cnt];
        if (dfs(cnt + 1, x))
            return true;

        if (num[i] == num[cnt])
            continue;
        if (num[i] > num[cnt])
            num[cnt+1] = num[i] - num[cnt];
        else
            num[cnt+1] = num[cnt] - num[i];
        if (dfs(cnt + 1, x))
            return true;
    }

    return false;
}

int main() {
    while (cin >> n and n) {
        for (max_dep = 0; ; max_dep++) {
            num[0] = 1;
            if (dfs(0, 1)) {
                cout << max_dep << endl;
                break;
            }
        }
    }

    return 0;
}


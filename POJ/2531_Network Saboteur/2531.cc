#include <iostream>
#include <cstring>

using namespace std;

int n;
int cost[20][20];
int array[20];
int ans = 0;

int dfs(int x, int sum) {
    // 将第 x 个加入并计算总和
    array[x] = 1;
    for (int i = 0; i < n; i++) {
        if (array[i] == array[x])
            sum -= cost[x][i];
        else
            sum += cost[x][i];
    }
    if (sum > ans)
        ans = sum;
    
    // 依次加入后续元素并更新总和
    for (int i = x + 1; i < n; i++) {
        dfs(i, sum);
        array[i] = 0;
    }
}

int main() {

    cin >> n;
    memset(cost, 0, sizeof(cost));
    memset(array, 0, sizeof(array));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}


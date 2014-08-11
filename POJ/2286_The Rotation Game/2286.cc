#include <iostream>
#include <algorithm>

using namespace std;

int matrix[24];
char path[100];
int max_dep;

int count_rem() {
    // 计算最少所需步数
    int count[4] = {0};

    count[matrix[6]]++, count[matrix[7]]++, count[matrix[8]]++;
    count[matrix[11]]++, count[matrix[12]]++;
    count[matrix[15]]++, count[matrix[16]]++, count[matrix[17]]++;

    // return 8 - max({count[1], count[2], count[3]}); // c++11
    return 8 - max(max(count[1], count[2]), count[3]);
}

bool dfs(int depth) {
    static int dir[8][7] = {{ 0,  2,  6, 11, 15, 20, 22}, // A
                            { 1,  3,  8, 12, 17, 21, 23}, // B
                            {10,  9,  8,  7,  6,  5,  4}, // C
                            {19, 18, 17, 16, 15, 14, 13}, // D
                            {23, 21, 17, 12,  8,  3,  1}, // E
                            {22, 20, 15, 11,  6,  2,  0}, // F
                            {13, 14, 15, 16, 17, 18, 19}, // G
                            { 4,  5,  6,  7,  8,  9, 10}, // H
                           };

    int rem = count_rem();
    if (rem == 0)
        return true;
    if (max_dep - depth < rem) // 剪枝
        return false;

    for (int k = 0; k < 8; k++) {
        // 移动
        int tmp = matrix[dir[k][0]];
        for (int i = 0; i < 6; i++)
            matrix[dir[k][i]] = matrix[dir[k][i+1]];
        matrix[dir[k][6]] = tmp;
        
        // 记录路径
        path[depth + 1] = 'A' + k;

        // 搜索
        if (dfs(depth + 1))
            return true;

        // 回溯
        tmp = matrix[dir[k][6]];
        for (int i = 6; i > 0; i--)
            matrix[dir[k][i]] = matrix[dir[k][i-1]];
        matrix[dir[k][0]] = tmp;
    }

    return false;
}

int main() {
    while (cin >> matrix[0] and matrix[0]) {
        for (int i = 1; i < 24; i++)
            cin >> matrix[i];

        max_dep = 0;
        while (dfs(0) == false)
            max_dep++;

        if (max_dep == 0) {
            cout << "No moves needed" << endl;
        } else {
            for (int i = 1; i <= max_dep; i++)
                cout << path[i];
            cout << endl;
        }
        cout << matrix[6] << endl;
    }

    return 0;
}

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int matrix[28][28];
int p, q;
deque<int> path;

inline bool inMatrix(int m, int n) {
    return m > 0 and m <= p and n > 0 and n <= q;
}

bool dfs(int m, int n) {
    static int dir[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1},
                            {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

    if (inMatrix(m, n) == false or matrix[m][n] == 1)
        return false;

    matrix[m][n] = 1;
    path.push_back(m * 26 + n);

    if (path.size() == p * q)
        return true;

    for (int i = 0; i < 8; i++) {
        int foo = m + dir[i][0];
        int bar = n + dir[i][1];
        if (dfs(foo, bar)) {
            return true;
        }
    }

    matrix[m][n] = 0;
    path.pop_back();
    return false;
}


int main() {
    
    int n;
    cin >> n;

    for (int index = 1; index <= n; index++) {
        memset(matrix, 0, sizeof(matrix));
        path.clear();
        cin >> p >> q;

        cout << "Scenario #" << index << ":" << endl;

        bool flag = false;
        for (int k = 1; k <= q; k++) {
            for (int j = 1; j <= p; j++) {
                if (dfs(j, k)) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            while (not path.empty()) {
                int var = path.front();
                cout << (char) (var % 26 - 1 + 'A') << var / 26;
                path.pop_front();
            }
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
        cout << endl;
    }

    return 0;
}


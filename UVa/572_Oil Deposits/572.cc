#include <iostream>
#include <string.h>

using namespace std;

char maze[102][102];
int m, n;

bool search(int i, int j);

int main() {

	while (cin >> m >> n) {
        if (m == 0 or n == 0)
            break;

        // input
        memset(maze, '*', sizeof(maze));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> maze[i][j];

        int count = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (maze[i][j] == '@') {
                    count++;
                    search(i, j);                
                }

        cout << count << endl;
	}

    return 0;
}

bool search(int y, int x) {
    static int dirX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    static int dirY[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    maze[y][x] = '*';

    bool flag = false;
    for (int i = 0; i < 8; i++)
        if (maze[y + dirY[i]][x + dirX[i]] == '@') {
            flag = true;
            search(y + dirY[i], x + dirX[i]);
        }

    return flag;
}

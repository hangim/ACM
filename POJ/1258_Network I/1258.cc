#include <iostream>
#include <algorithm>

using namespace std;

#define MaxSize 100
const int INF = 2000000000;

int n;
int matrix[MaxSize][MaxSize];
int dist[MaxSize];
int visited[MaxSize];

void update(int x) {
    visited[x] = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;
        dist[i] = min(dist[i], matrix[x][i]);
    }
}

int getNextMin() {
    int index = -1;
    int minn = INF;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        if (dist[i] < minn) {
            minn = dist[i];
            index = i;
        }
    }

    return index;
}

int prime() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    int total = 0;
    int now = 0;
    dist[now] = 0;

    do {
        total += dist[now];
        update(now);
    } while ((now = getNextMin()) != -1);

    return total;
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << prime() << endl;
    }

    return 0;
}


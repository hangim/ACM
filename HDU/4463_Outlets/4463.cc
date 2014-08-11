#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 1e9

struct Point {
    int x;
    int y;
} point[50];

int visited[50];
double dist[50];
int n;

double get_dist(int a, int b) {
    return sqrt(pow(point[a].x - point[b].x, 2.0)
        + pow(point[a].y - point[b].y, 2.0));
}

int get_min_index() {
    int index = -1;
    double min = INF;
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        if (min > dist[i]) {
            index = i;
            min = dist[i];
        }
    }
    return index;
}

void update_dist(int x) {
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        double tmp = get_dist(x, i);

        if (tmp < dist[i])
            dist[i] = tmp;
    }
}

double prim(int nike, int apple) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    double total = 0;

    dist[nike] = 0;
    visited[nike] = 1;
    update_dist(nike);

    int now = apple;
    do {
        visited[now] = 1;
        total += dist[now];
        update_dist(now);
    } while ((now = get_min_index()) != -1);
    
    return total;
}

int main() {
    while (cin >> n) {
        if (n == 0)
            break;

        int nike, apple;
        cin >> nike >> apple;
        for (int i = 0; i < n; i++) {
            cin >> point[i].x >> point[i].y;
        }
        
        cout << setprecision(2) << fixed
             << prim(nike - 1, apple - 1) << endl;
    
    }

    return 0;
}


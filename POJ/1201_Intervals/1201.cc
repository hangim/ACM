#include <iostream>
#include <cstring>

using namespace std;

int n;
int d[50001];
int min_num = 50001, max_num = 0;
struct Edge {
    int u, v;
    int c;
} e[50000];

bool bellMan_ford() {
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        bool flag = true;
        
        for (int j = 0; j < n; j++) {
            if (d[e[j].v] < d[e[j].u] + e[j].c) {
                d[e[j].v] = d[e[j].u] + e[j].c;
                flag = false;
            }
        }

        for (int j = min_num; j < max_num; j++) {
            if (d[j+1] < d[j]) {
                d[j+1] = d[j];
                flag = false;
            }
        }

        for (int j = max_num; j > min_num; j--) {
            if (d[j-1] < d[j] - 1) {
                d[j-1] = d[j] - 1;
                flag = false;
            }
        }

        if (flag)
            return true;
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> e[i].u >> e[i].v >> e[i].c;
        e[i].u--;
        min_num = min(min_num, e[i].u);
        max_num = max(max_num, e[i].v);
    }
    
    bellMan_ford();
    cout << d[max_num] << endl;

    return 0;
}


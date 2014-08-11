#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int adj[26][26];
bool hasCycle, hasSorted;
int order[26];

void topSort() {
    int in_degree[26] = {0};
    int vis[26] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            in_degree[j] += adj[i][j];
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (not vis[j] and in_degree[j] == 0) {
                vis[j] = 1;
                order[len++] = j;
                for (int k = 0; k < n; k++) {
                    in_degree[k] -= adj[j][k]; // update in_degree
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (in_degree[i]) {
            hasCycle = true;
            return;
        }
    }
    
    if (len == n)
        hasSorted = true;
    for (int i = 0; i < n - 1; i++)
        if (adj[order[i]][order[i+1]] == 0)
            hasSorted = false;
}

int main() {
    while (cin >> n >> m and n + m) {
        hasCycle = hasSorted = false;
        memset(adj, 0, sizeof(adj));
        int ans = -1;

        for (int i = 1; i <= m; i++) {
            char u, v;
            cin >> u >> v >> v;
            cin.get();
            adj[u - 'A'][v - 'A'] = 1;
            
            if (hasCycle or hasSorted)
                continue;
            topSort();
            if (hasCycle or hasSorted)
                ans = i;
        }

        if (ans == -1) {
            cout << "Sorted sequence cannot be determined." << endl;
        }
        if (hasCycle) {
            cout << "Inconsistency found after "
                 << ans << " relations." << endl;
        }
        if (hasSorted) {
            cout << "Sorted sequence determined after "
                 << ans << " relations: ";
            for (int i = 0; i < n; i++)
                cout << (char) ('A' + order[i]);
            cout << "." << endl;
        }
    }

    return 0;
}


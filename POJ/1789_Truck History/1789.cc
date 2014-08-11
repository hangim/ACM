#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = 1 << 29;
int n;
int adj[2000][2000];

int prim() {
    int vis[2000] = {0};
    int d[2000];

    int sum = 0;
    for (int i = 0; i < n; i++)
        d[i] = INF;

    int now = 0;
    for (int k = 0; k < n - 1; k++) {
        vis[now] = 1;
        
        int min_dist = INF;
        int next;
        
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            d[i] = min(d[i], adj[now][i]);
            if (d[i] < min_dist) {
                min_dist = d[i];
                next = i;
            }
        }

        sum += d[next];
        now = next;
    }

    return sum;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<string> v(2000);
    while (cin >> n and n) {
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            v[i] = s;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                adj[i][j] = 0;
                for (int k = 0; k < 7; k++) {
                    if (v[i][k] != v[j][k])
                        adj[i][j]++;
                }
                adj[j][i] = adj[i][j];
            }
        }

        cout << "The highest possible quality is 1/"
             << prim() << "." << endl;
    }

    return 0;
}


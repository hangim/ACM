#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

int n, m, k;
vector<int> e[100001];
int vis[100001];

int main () {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) {
        for (int i = 0; i < 100001; i++)
            e[i].clear();
        memset(vis, 0, sizeof(vis));

        set<int> s;
        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            int var;
            cin >> var;
            s.insert(var);
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }

        int l;
        cin >> l;
        vector<int> v;
        for (int i = 0; i < l; i++) {
            int var;
            cin >> var;
            v.push_back(var);
        }

        if (l != k) {
            cout << "No" << endl;
            continue;
        }
    
        v.push_back(-1);
        vis[v[0]] = 1;
        for (int x = 0; x < v.size() - 1; x++) {
            if (not vis[v[x]])
                break;

            queue<int> q;
            q.push(v[x]);
            
            while (not q.empty()) {
                int u = q.front();
                // cout << u << endl;
                q.pop();

                for (int i = 0; i < e[u].size(); i++) {
                    int &next = e[u][i];
                    if (s.find(next) != s.end()) {
                        vis[next] = 1;
                        continue;
                    }
                    if (not vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
            // cout << endl;
        }

        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (not vis[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <string>

using namespace std;

vector<int> edge[1001];
const int INF = 9999;
int n;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int bfs(int x) {
    static int visited[1001];
    static int dist[1001];
    
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[x] = 0;
    queue<int> q;
    q.push(x);
    
    while (not q.empty()) {
        int now;
        now = q.front();
        q.pop();
        
        int total = edge[now].size();
        for (int i = 0; i < total; i++) {
            int next = edge[now][i];
            if (visited[next])
                continue;

            dist[next] = dist[now] + 1;
            visited[next] = 1;
            q.push(next);
        }
    }

    // return max distance
    int max_distance = 0;
    for (int i = 0; i < n; i++)
        max_distance = max(max_distance, dist[i]);

    return max_distance;
}

int main() {
    ios::sync_with_stdio(false);

    while (cin >> n) {
        if (n == 0)
            break;
        
        for (int i = 0; i < n; i++)
            edge[i].clear();

        // input vertex
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            mp[name] = i;
        }

        // input edge
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string from;
            string to;
            cin >> from >> to;
            
            edge[mp[from]].push_back(mp[to]);
            edge[mp[to]].push_back(mp[from]);
        }

        // get max distance
        int max_distance = 0;
        for (int i = 0; i < n; i++) {
            int now_distance = bfs(i);
            max_distance = max(max_distance, now_distance);
        }
        
        if (max_distance == INF)
            cout << -1 << endl;
        else
            cout << max_distance << endl;
    }

    return 0;
}


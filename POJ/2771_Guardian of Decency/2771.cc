#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int height;
    string sex;
    string music;
    string sport;
};

vector<struct Person> boys;
vector<struct Person> girls;
int adj[501][501];

int vis[501];
int match[501];

bool dfs(int u) {
    for (int v = girls.size() - 1; v >= 0; v--) {
        if (not vis[v] and adj[u][v]) {
            vis[v] = 1;
            if (match[v] == -1 or dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }

    return false;
}

int hungary() {
    int ans = 0;
    memset(match, -1, sizeof(match));

    for (int u = boys.size() - 1; u >= 0; u--) {
        memset(vis, 0, sizeof(vis));
        if (dfs(u))
            ans++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        boys.clear();
        girls.clear();
    
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            struct Person p;
            cin >> p.height >> p.sex >> p.music >> p.sport;

            if (p.sex == "M")
                boys.push_back(p);
            else
                girls.push_back(p);
        }

        memset(adj, 0, sizeof(adj));
        for (int u = boys.size() - 1; u >= 0; u--) {
            for (int v = girls.size() - 1; v >= 0; v--) {
                struct Person &boy = boys[u];
                struct Person &girl = girls[v];

                if (boy.height - girl.height <= 40
                    and girl.height - boy.height <= 40
                    and boy.music == girl.music
                    and boy.sport != girl.sport) {
                    adj[u][v] = 1;
                }
            }
        }

        cout << t - hungary() << endl;
    }

    return 0;
}


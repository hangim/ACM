#include <iostream>
#include <cstring>

using namespace std;

const int INF = 1 << 30;

int M[101];
struct {
    int d, l, t;
    int next;
} road[10001];

int visit[101];

int k, n, r;
int ans;

void dfs(int x, int len, int rem) {
    if (x == n) {
        ans = min(ans, len);
        return;
    }

    if (len > ans)
        return;
    
    for (int i = M[x]; i != -1; i = road[i].next) {
        int &d = road[i].d;
        int &l = road[i].l;
        int &t = road[i].t;

        if (not visit[d] and t <= rem) {
            visit[d] = 1;
            dfs(d, len + l, rem - t);
            visit[d] = 0;
        }
    }
}

int main() {
    memset(M, -1, sizeof(M));
    memset(visit, 0, sizeof(visit));

    cin >> k >> n >> r;

    for (int i = 0; i < r; i++) {
        int s, d, l, t;
        cin >> s >> d >> l >> t;
        road[i].d = d;
        road[i].l = l;
        road[i].t = t;
        
        road[i].next = M[s];
        M[s] = i;
    }

    ans = INF;
    dfs(1, 0, k);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}


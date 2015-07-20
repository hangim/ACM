#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int A, B, C, D;
double dp[15][15][15][15][5][5];
bool used[15][15][15][15][5][5];

double dfs(int rA, int rB, int rC, int rD, int j1, int j2) {
    if (rA < 0 or rB < 0 or rC < 0 or rD < 0)
        return 0;
    int a = 13 - rA + (j1 == 1) + (j2 == 1);
    int b = 13 - rB + (j1 == 2) + (j2 == 2);
    int c = 13 - rC + (j1 == 3) + (j2 == 3);
    int d = 13 - rD + (j1 == 4) + (j2 == 4);

    if (a >= A and b >= B and c >= C and d >= D)
        return 0;

    if (rA == 0 and rB == 0 and rC == 0 and rD == 0 and j1 and j2)
        return INF;

    if (used[rA][rB][rC][rD][j1][j2])
        return dp[rA][rB][rC][rD][j1][j2];
    used[rA][rB][rC][rD][j1][j2] = true;

    int remain = rA + rB + rC + rD + (j1 == 0) + (j2 == 0);
    double ret = 0;
    ret += 1.0 * rA / remain * (1 + dfs(rA - 1, rB, rC, rD, j1, j2));
    ret += 1.0 * rB / remain * (1 + dfs(rA, rB - 1, rC, rD, j1, j2));
    ret += 1.0 * rC / remain * (1 + dfs(rA, rB, rC - 1, rD, j1, j2));
    ret += 1.0 * rD / remain * (1 + dfs(rA, rB, rC, rD - 1, j1, j2));

    if (j1 == 0) {
        double tmp = INF;
        for (int i = 1; i <= 4; ++i)
            tmp = min(tmp, 1.0 / remain * (1 + dfs(rA, rB, rC, rD, i, j2)));
        ret += tmp;
    }

    if (j2 == 0) {
        double tmp = INF;
        for (int i = 1; i <= 4; ++i)
            tmp = min(tmp, 1.0 / remain * (1 + dfs(rA, rB, rC, rD, j1, i)));
        ret += tmp;
    }

    return dp[rA][rB][rC][rD][j1][j2] = ret;
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        cin >> A >> B >> C >> D;
        memset(used, 0, sizeof(used));
        double ans = dfs(13, 13, 13, 13, 0, 0);
        if (ans > 54)
            ans = -1;
        cout << "Case " << cases << ": "
             << setprecision(6) << fixed << ans << endl;
    }
    return 0;
}


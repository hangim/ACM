#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int N, M, K;
        double P;
        cin >> N >> M >> K >> P;
        cout << "Case " << cases << ": "
             << setprecision(6) << N * P * K << endl;
    }
    return 0;
}


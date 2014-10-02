#include <iostream>
#include <iomanip>

using namespace std;

int a[5] = {100, 84, 79, 74, 69};
int b[5] = {85, 80, 75, 70, 60};
double c[5] = {4.0, 3.5, 3.0, 2.5, 2.0};

int score, n;
int total;
double high, low;

void dfs(int k, int rem, int h, int l, double w) {
    if (k == 5) {
        if (rem == 0 and total >= l and total <= h) {
            high = max(w, high);
            low = min(w, low);
        }
        return;
    }
    if (h + rem * a[k] < total or l + rem * 60 > total)
        return;
    if (w + rem * c[k] < high and w + rem * 2.0 > low)
        return;

    for (int i = 0; i <= rem; i++) {
        dfs(k + 1, rem - i, h + i * a[k], l + i * b[k], w + i * c[k]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        high = 0;
        low = 40;
        cin >> score >> n;
        total = score * n;
        dfs(0, n, 0, 0, 0);
        cout << setprecision(4) << fixed << low / n
             << " " << high / n << endl;
    }

    return 0;
}


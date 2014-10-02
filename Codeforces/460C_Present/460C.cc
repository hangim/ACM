#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, m, w;
    cin >> n >> m >> w;
    vector<int> a(n);
    int l = INT_MAX, r = INT_MIN; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        l = min(l, a[i]);
        r = max(r, a[i]);
    }
    
    r += m;
    vector<int> st(n+w);
    int ans;
    while (l <= r) {
        int mid = l + (r-l)/2;
        fill(st.begin(), st.end(), 0);

        int day = m;
        for (int t = 0, i = 0; i < n; i++) {
            t += st[i];
            if (a[i] + t < mid) {
                int var = mid - a[i] - t;
                day -= var;
                t += var;
                st[i+w] -= var;
                if (day < 0)
                    break;
            }
        }

        if (day > 0) {
            ans = mid;
            l = mid + 1;
        } else if (day < 0) {
            r = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}


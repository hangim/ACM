#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000;
int a[maxn + 10];

int dp1[maxn + 10], dp2[maxn + 10], dp3[maxn + 10];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        int n, l;
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);



        vector<int> v1, v2, v3;
        for (int i = 0; i + l < n; ++i) {
            int n1 = upper_bound(v1.begin(), v1.end(), a[i]) - v1.begin();
            if (n1 == v1.size())
                v1.push_back(a[i]);
            else
                v1[n1] = a[i];
            dp1[i] = n1 + 1;
        }

        for (int i = l; i < n; ++i) {
            if (i == l) {
                dp2[i] = 1;
                continue;
            }
            int n2 = upper_bound(v2.begin(), v2.end(), a[i-l-1]) - v2.begin();
            if (n2 == v2.size())
                v2.push_back(a[i-l-1]);
            else
                v2[n2] = a[i-l-1];

            int n21 = upper_bound(v2.begin(), v2.end(), a[i]) - v2.begin();
//            cout << "n21 " << n21 << endl;
            dp2[i] = n21 + 1;
        }

        for (int i = n - 1; i >= l; i--) {
            int n3 = upper_bound(v3.begin(), v3.end(), -a[i]) - v3.begin();
            if (n3 == v3.size())
                v3.push_back(-a[i]);
            else
                v3[n3] = -a[i];
            dp3[i] = n3;
        }



        int ans = 0;
        for (int i = 0; i + l < n; ++i) {
            ans = max(ans, dp1[i]);
//            cout << "a " << dp1[i] << endl;
        }
        for (int i = l; i < n; ++i) {
            ans = max(ans, dp2[i] + dp3[i]);
//            cout << "b " << dp2[i] + dp3[i] << endl;
        }



        printf("Case #%d: %d\n", cs, ans);


/*
        for (int i = 0; i < n; ++i)
            cout << dp1[i] << " ";
        cout << endl;

        for (int i = 0; i < n; ++i)
            cout << dp2[i] << " ";
        cout << endl;

        for (int i = 0; i < n; ++i)
            cout << dp3[i] << " ";
        cout << endl;
*/
    }

    return 0;
}


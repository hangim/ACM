#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num(n+1, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int var = 0;
    int ans = 0;
    for (auto it : num) {
        if (it) {
            var++;
        } else if (var) {
            ans += var + 1;
            var = 0;
        }
    }
    ans = max(0, ans - 1);
    cout << ans << endl;

    return 0;
}


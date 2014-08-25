#include <iostream>

using namespace std;

int main() {
    int scores[52] = {0};
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> scores[i];
    while (scores[k] > 0 and scores[k+1] == scores[k])
        k++;
    while (scores[k] == 0 and k != 0)
        k--;
    cout << k << endl;

    return 0;
}


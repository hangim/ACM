#include <iostream>

using namespace std;

int main() {

    int num[1001];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    int maxx = -1;
    int index = -1;
    for (int i = 1; i <= n - 2; i++) {
        int var = num[i] + num[i+1] + num[i+2];
        if (var > maxx) {
            maxx = var;
            index = i + 1;
        }
    }

    cout << maxx << " " << index << endl;

    return 0;
}


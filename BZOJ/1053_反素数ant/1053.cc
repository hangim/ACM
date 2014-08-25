#include <iostream>

using namespace std;

int prime[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

long long n;
long long num = 0;
int total = 0;

void dfs(int index, long long now, int cnt) {
    if (index == 11) {
        if (cnt > total or (cnt == total and now <= num)) {
            total = cnt;
            num = now;
        }
        return;
    }

    for (int i = 0; ; i++) {
        dfs(index + 1, now, cnt * (i + 1));
        now *= prime[index];
        if (now > n)
            break;
    }
}

int main() {
    cin >> n;
    dfs(1, 1, 1);
    cout << num << endl;

    return 0;
}


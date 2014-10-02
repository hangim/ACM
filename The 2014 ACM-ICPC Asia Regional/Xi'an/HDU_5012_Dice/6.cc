#include <iostream>

using namespace std;

int deep;
int ans;

int A[7];
int B[7];

void left() {
    int tmp = A[2];
    A[2] = A[3];
    A[3] = A[1];
    A[1] = A[4];
    A[4] = tmp;
}

void right() {
    int tmp = A[2];
    A[2] = A[4];
    A[4] = A[1];
    A[1] = A[3];
    A[3] = tmp;
}

void front() {
    int tmp = A[2];
    A[2] = A[5];
    A[5] = A[1];
    A[1] = A[6];
    A[6] = tmp;
}

void back() {
    int tmp = A[2];
    A[2] = A[6];
    A[6] = A[1];
    A[1] = A[5];
    A[5] = tmp;
}

void dfs(int x) {
    if (ans != -1)
        return;

    bool flag = true;
    for (int i = 1; i <= 6; i++)
        flag &= (A[i] == B[i]);
    if (flag) {
        ans = x;
        return;
    }

    if (x == deep)
        return;

    // left
    left();
    dfs(x+1);
    right();

    // right
    right();
    dfs(x+1);
    left();

    // front
    front();
    dfs(x+1);
    back();

    // back
    back();
    dfs(x+1);
    front();
}

int main() {
    while (cin >> A[1]) {
        for (int i = 2; i <= 6; i++)
            cin >> A[i];
        for (int i = 1; i <= 6; i++)
            cin >> B[i];

        ans = -1;
        for (deep = 0; ans == -1 and deep <= 4; deep++)
            dfs(0);
        cout << ans << endl;
    }

    return 0;
}


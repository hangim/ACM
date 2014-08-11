#include <iostream>
#include <queue>

using namespace std;

long long bfs(int n) {
    queue<long long> q;

    q.push(1);
    
    while (not q.empty()) {
        long long foo = q.front();
        if (foo % n == 0)
            return foo;

        q.pop();
        q.push(foo * 10);
        q.push(foo * 10 + 1);
    }
    
    return -1;
}

int main() {

    // for (int i = 1; i < 200; i++)
    //    cout << bfs(i) << endl;
    int n;
    while (cin >> n and n) {
        cout << bfs(n) << endl;
    }

    return 0;
}


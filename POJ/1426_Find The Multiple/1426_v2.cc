#include <iostream>
#include <queue>
#include <map>

using namespace std;

long long bfs(int n) {
    queue<int> q;
    map<int, long long> m;

    q.push(1);
    m[1] = 1;
    
    while (not q.empty()) {
        int foo = q.front();

        if (foo % n == 0)
            return m[foo];
        
        q.pop();

        int bar;
        bar = foo * 10 % n;
        if (m.find(bar) == m.end()) {
            m[bar] = m[foo] * 10;
            q.push(bar);
        }

        bar = (foo * 10 + 1) % n;
        if (m.find(bar) == m.end()) {
            m[bar] = m[foo] * 10 + 1;
            q.push(bar);
        }

    }
    
    return -1;
}

int main() {

    int n;
    while (cin >> n and n) {
        cout << bfs(n) << endl;
    }

    return 0;
}


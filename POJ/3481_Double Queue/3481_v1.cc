#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    int op, k, p;
    while (scanf("%d", &op) and op) {
        if (op == 1) {
            scanf("%d%d", &k, &p);
            m.insert(make_pair(p, k));
        } else if (m.empty()) {
            printf("0\n");
        } else if (op == 2) {
            printf("%d\n", (--m.end())->second);
            m.erase(--m.end());
        } else if (op == 3) {
            printf("%d\n", m.begin()->second);
            m.erase(m.begin());
        }
    }

    return 0;
}


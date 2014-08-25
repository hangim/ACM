#include <cstdio>
#include <set>

using namespace std;

struct Node {
    int k;
    int p;

    Node(int a, int b) : k(a), p(b){
    }

    friend bool operator < (Node a, Node b) {
        return a.p < b.p;
    }
};

int main() {
    set<Node> s;
    int op, k, p;
    while (scanf("%d", &op) and op) {
        if (op == 1) {
            scanf("%d%d", &k, &p);
            s.insert(Node(k, p));
        } else if (s.empty()) {
            printf("0\n");
        } else if (op == 2) {
            printf("%d\n", (--s.end())->k);
            s.erase(--s.end());
        } else if (op == 3) {
            printf("%d\n", s.begin()->k);
            s.erase(s.begin());
        }
    }

    return 0;
}


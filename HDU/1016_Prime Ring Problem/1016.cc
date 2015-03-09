#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> e[20];
set<int> s;

struct Node {
    int used;
    int size;
    int data[20];

    Node() : used(0), size(0) {}

    int back() {
        return data[size - 1];
    }

    bool has(int it) {
        return used & (1 << it);
    }

    void add(int it) {
        used |= (1 << it);
        data[size++] = it;
    }

    void out() {
        for (int i = 0; i < size; ++i)
            printf("%d%c", data[i], i != size - 1 ? ' ' : '\n');
    }
};

void init() {
    int v[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 39};
    
    for (int i = 0; i != sizeof(v); ++i)
        s.insert(v[i]);

    for (int i = 1; i < 20; ++i) {
        for (int j = 0; j != sizeof(v); ++j) {
            if (v[j] > i and v[j] != 2 * i)
                e[i].push_back(v[j] - i);
        }
    }
}

void bfs(int n) {
    queue<Node> q;

    Node node;
    node.add(1);
    q.push(node);
    
    while (not q.empty()) {
        node = q.front();
        q.pop();

        if (node.size == n) {
            if (s.find(node.back() + 1) != s.end()) {
                node.out();
            }
            continue;
        }

        for (int i = 0; i != e[node.back()].size(); ++i) {
            int &it = e[node.back()][i];
            if (it > n)
                break;

            if (node.has(it))
                continue;

            Node next = node;
            next.add(it);
            q.push(next);
        }
    }
}

int main() {
    init();
    
    int cases = 1;
    int n;
    while (scanf("%d", &n) == 1) {
        printf("Case %d:\n", cases++);
        bfs(n);
        printf("\n");
    }

    return 0;
}


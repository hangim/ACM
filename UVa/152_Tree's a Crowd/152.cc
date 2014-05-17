#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct {
    int x;
    int y;
    int z;
} Tree;

int getDist(Tree &a, Tree &b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
}

int main() {

    int rsu[10] = {0};
    Tree tree[5001];

    int n = 0;
    while (cin >> tree[n].x >> tree[n].y >> tree[n].z) {
        if (tree[n].x == 0 and tree[n].y == 0 and tree[n].z == 0)
            break;
        n++;
    }

    for (int i = 0; i < n; i++) {
        int d = 10;
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            d = min(d, getDist(tree[i], tree[j]));
        }
        if (d < 10)
            rsu[d]++;
    }
    
    for (int i = 0; i < 10; i++)
        cout << setw(4) << rsu[i];
    cout << endl;

    return 0;
}

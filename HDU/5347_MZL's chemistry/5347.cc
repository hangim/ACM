#include <bits/stdc++.h>

using namespace std;

int table[90] = {
0,1312, 2372, 520, 932, 800, 1086, 1402, 1313, 1681,
2080, 495, 737, 577, 786, 1011, 999, 1251, 1520, 418, 589,
633, 658, 650, 653, 717, 762, 760, 737, 745, 906,
578, 762, 947, 941, 1139, 1350, 403, 549, 600,
640, 652, 684, 702, 710, 719, 804, 731, 867, 558, 708, 834, 869, 1008,
1170, 375, 502, 538, 634, 527, 533, 540, 544, 547, 593, 565, 573, 581,
589, 596, 603, 523, 658, 761, 770, 760, 840, 870, 890,
1007, 589, 715, 703, 812, 890, 1037
};

int main() {
    int u, v;
    while (scanf("%d %d", &u, &v) != EOF) {
        if (table[u] > table[v])
            puts("FIRST BIGGER");
        else
            puts("SECOND BIGGER");
    }
    return 0;
}


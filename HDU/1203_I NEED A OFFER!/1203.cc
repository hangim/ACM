#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

typedef struct {
    int money;
    double possible;
    double c;
} school;

int cmp(const void *a, const void *b) {
    school *_a = (school *) a;
    school *_b = (school *) b;
    return _a->money > _b->money;
}

int main() {

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 and m == 0)
            break;

        school *schools = new school[m];
        for (int i = 0; i < m; i++) {
            cin >> schools[i].money >> schools[i].possible;
            schools[i].c = schools[i].money / schools[i].possible;
        }
        qsort(schools, m, sizeof(school), cmp);

        double *possible = new double[n + 1];
        for (int i = 0; i <= n; i++)
            possible[i] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = n; j >= schools[i].money; j--) {
                double var = possible[j - schools[i].money]
                    * (1 - schools[i].possible);
                if (var < possible[j]) {
                    possible[j] = var;
                }
            }
        }

        cout << setprecision(1) << fixed << (1 - possible[n]) * 100
            << "%" << endl;
    }

    return 0;
}

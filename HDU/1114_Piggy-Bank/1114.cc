#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    int p;
    int w;
} Coin;

int cmp(const void *a, const void *b) {
    Coin *_a = (Coin *) a;
    Coin *_b = (Coin *) b;
    return _a->w > _b->w;
}

const int MAXX = 0x7FFFFFFF;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int e, f;
        cin >> e >> f;

        int n;
        cin >> n;
        Coin *coin = new Coin[n];
        for (int i = 0; i < n; i++) {
            cin >> coin[i].p >> coin[i].w;
        }
        qsort(coin, n, sizeof(Coin), cmp);

        int *money = new int[10001];
        for (int i = e; i <= f; i++)
            money[i] = MAXX;
        money[e] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = e; j + coin[i].w <= f; j++) {
                if (money[j] == MAXX)
                    continue;

                int var = money[j] + coin[i].p;
                if (var < money[j + coin[i].w])
                    money[j + coin[i].w] = var;
            }
        }

        if (money[f] != MAXX)
            cout << "The minimum amount of money in the piggy-bank is "
                 << money[f] << "." << endl;
        else
            cout << "This is impossible." << endl;
    }

    return 0;
}

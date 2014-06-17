#include <iostream>
#include <cstdlib>

using namespace std;

struct song {
    int id;
    int length;
    double freq;
};

int comp(const void *a, const void *b) {
    // sorted by (freq / length) decrease
    struct song *_a = (struct song *) a;
    struct song *_b = (struct song *) b;
    return _a->freq / _a->length > _b->freq / _b->length ? -1 : 1;
}

int main() {

    int n;
    while (cin >> n) {
        struct song *songs = new struct song[n];
        for (int i = 0; i < n; i++)
            cin >> songs[i].id >> songs[i].length >> songs[i].freq;

        qsort(songs, n, sizeof(struct song), comp);

        int m;
        cin >> m;
        cout << songs[m - 1].id << endl;
    }

    return 0;
}


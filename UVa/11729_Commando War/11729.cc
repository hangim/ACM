#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Person {
    int b;
    int j;
    int total;
};

int cmp(struct Person a, struct Person b) {
    return a.j > b.j;
}

int main() {
    int n;
    int index = 1;
    while (cin >> n and n) {
        vector<struct Person> v;
        for (int i = 0; i < n; i++) {
            struct Person tmp;
            cin >> tmp.b >> tmp.j;
            tmp.total = tmp.b + tmp.j;
            v.push_back(tmp);
        }

        sort(v.begin(), v.end(), cmp);

        int now = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total = max(now + v[i].total, total);
            now += v[i].b;
        }

        cout << "Case " << index++ << ": " << total << endl;

    }
    
    return 0;
}


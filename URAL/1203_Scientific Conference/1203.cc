#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Report {
    int start;
    int end;
    
    Report(int start, int end) {
        this->start = start;
        this->end = end;
    }

    bool operator < (const struct Report &o) const {
        return this->end < o.end;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector<struct Report> v;
        
        for (int i = 0; i < n; i++) {
            int start, end;
            cin >> start >> end;
            v.push_back(*new struct Report(start, end));
        }

        sort(v.begin(), v.end());

        int end = -1;
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (end + 1 <= v[i].start) {
                end = v[i].end;
                total++;
            }
        }
        cout << total << endl;
    }

    return 0;
}


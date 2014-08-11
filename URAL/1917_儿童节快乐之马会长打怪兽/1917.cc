// std=c++11

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int n, p;
    cin >> n >> p;
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp <= p) {
            if (m.find(tmp) == m.end())
                m[tmp] = 1;
            else
                m[tmp]++;
        }
    }

    int kill = 0, times = 0, last = 0;
    for (auto it : m) {
        int var;
        
        var = it.first * (last + it.second);
        if (var <= p) {
            kill += it.second;
            last += it.second;
            continue;
        }
        
        if (last > 0) {
            times++;
            last = 0;
        }
        
        var = it.first * it.second;
        if (var <= p) {
            kill += it.second;
            last = it.second;
        } else {
            break;
        }
    }

    // deal with the last one
    if (last > 0)
        times++;
    
    cout << kill << " " << times << endl;

    return 0;
}


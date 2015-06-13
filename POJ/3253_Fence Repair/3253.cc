#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

long long plank[20010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> plank[i];
    sort(plank, plank + n);

    priority_queue<int, vector<int>, greater<int> > q(plank, plank + n);
    long long sum = 0;
    while (q.size() > 1) {
        int a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        sum += a + b;
        q.push(a + b);
    }
    cout << sum << endl;
    return 0;
}


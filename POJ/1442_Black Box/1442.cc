#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int num[30001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int m, n;
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++)
        cin >> num[i];

    int k = 1;
    for (int j = 1; j <= n; j++) {
        int u;
        cin >> u;

        while (k <= u) {
            maxHeap.push(num[k++]);
        }
        while (maxHeap.size() >= j) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        cout << minHeap.top() << endl;
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    return 0;
}


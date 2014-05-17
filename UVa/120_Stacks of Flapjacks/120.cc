#include <iostream>

using namespace std;

void reverse(int *a, int l, int r) {
    while (l < r) {
        int t = a[l];
        a[l] = a[r];
        a[r] = t;

        l++;
        r--;
    }
}

int main() {

    int pancakes[31];

    int var;
    while (cin >> pancakes[1]) {
        int n = 1;
        while (cin.get() != '\n')
            cin >> pancakes[++n];

        for (int i = 1; i < n; i++)
            cout << pancakes[i] << " ";
        cout << pancakes[n] << endl;
        reverse(pancakes, 1, n);
        
        for (int i = 1; i < n; i++) {
            int index = i;
            for (int j = i + 1; j <= n; j++)
                if (pancakes[j] > pancakes[index])
                    index = j;
            if (index != i) {
                if (index == n) {
                    cout << i << " ";
                    reverse(pancakes, i, n);
                } else {
                    cout << index << " " << i << " ";
                    reverse(pancakes, index, n);
                    reverse(pancakes, i, n);
                }
            }
        }
        cout << 0 << endl;
    
    }
    return 0;
}

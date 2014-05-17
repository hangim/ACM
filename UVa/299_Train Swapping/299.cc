#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int bubble(int *a, int len) {
    int count = 0;
    for (int i = 0; i < len; i++)
        for (int j = len - 1; j > 0; j--)
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                count++;
            }

    return count;
}

int main() {

    int n;
    cin >> n;
    
    while (n--) {
        int l;
        cin >> l;
        int *train = new int[l];
        for (int i = 0; i < l; i++)
            cin >> train[i];
        
        cout << "Optimal train swapping takes " 
             << bubble(train, l) << " swaps." << endl;
    }

    return 0;
}

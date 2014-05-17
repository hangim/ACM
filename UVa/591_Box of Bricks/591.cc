#include <iostream>

using namespace std;

int main() {

    int index = 1;
    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        int *stacks = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> stacks[i];
            sum += stacks[i];
        }
        int avg = sum / n;
        
        int c = 0;
        for (int i = 0; i < n; i++)
            if (stacks[i] > avg)
                c += stacks[i] - avg;

        cout << "Set #" << index++ << endl
             << "The minimum number of moves is " << c << "."
             << endl << endl;
    }
    
    return 0;
}

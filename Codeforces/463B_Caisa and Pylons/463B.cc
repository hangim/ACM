#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int last = 0;
    int energy = 0;
    int paid = 0;
    for (int i = 0; i < n; i++) {
        int now;
        cin >> now;
        energy += last - now;
        last = now;
        if (energy < 0) {
            paid -= energy;
            energy = 0;
        }
    }

    cout << paid << endl;

    return 0;
}


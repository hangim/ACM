#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> hill(10);
    for (int i = 0; i < 10; i++)
        cin >> hill[i];

    sort(hill.begin(), hill.end());
    cout << hill[9] << endl
         << hill[8] << endl
         << hill[7] << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
    std::locale loc;

    int k, e;
    int index = 1;
    while (cin >> k >> e) {
        cin.get();
        string *keyword = new string[k];
        string *excuse = new string[e];
        string *excuseLower = new string[e];
        int *times = new int[e];
        int maxTimes = 0;

        // input
        for (int i = 0; i < k; i++) {
            getline(cin, keyword[i]);
        }
        for (int i = 0; i < e; i++) {
            getline(cin, excuse[i]);
            excuseLower[i] = excuse[i];
            transform(excuseLower[i].begin(), excuseLower[i].end(), excuseLower[i].begin(), ::tolower);
        }

        // calc
        for (int i = 0; i < e; i++) {
            times[i] = -1;
            for (int j = 0; j < k; j++) {
                int pos = -1;
                while ((pos = excuseLower[i].find(keyword[j], pos + 1)) != excuseLower[i].npos) {
                    if (pos == 0 or pos + keyword[j].length() == excuseLower[i].length()
                        or (not isalpha(excuseLower[i][pos - 1], loc)
                            and not isalpha(excuseLower[i][pos + keyword[j].length()], loc)))
                        times[i]++;
                }
                maxTimes = max(times[i], maxTimes);
            }
        }

        // output
        cout << "Excuse Set #" << index++ << endl;
        for (int i = 0; i < e; i++)
            if (times[i] == maxTimes)
                cout << excuse[i] << endl;
        cout << endl;
    }

    return 0;
}

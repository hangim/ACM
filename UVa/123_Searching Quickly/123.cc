#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> ignores;
vector< vector<string> > titles;
vector<string> keyword;

void input();
void testOutput();

int main() {

    input();
    // testOutput();

    // output
    for (int i = 0; i < keyword.size(); i++) {
        for (int j = 0; j < titles.size(); j++) {
            int k = 0;
            while (true) { 
                while (k < titles[j].size() and titles[j][k] != keyword[i])
                    k++;
                if (k == titles[j].size())
                    break;

                for (int q = 0; q < titles[j].size(); q++) {
                    string var = titles[j][q];
                    if (q != k) {
                        cout << var;
                    } else {
                        transform(var.begin(), var.end(), var.begin(), ::toupper);
                        cout << var;
                    }

                    if (q == titles[j].size() - 1)
                        cout << endl;
                    else
                        cout << " ";
                }
                k++;
            }
        }
    }

    return 0;
}

void input() {
    // input ignores
    while (true) {
        string var;
        cin >> var;
        if (var == "::")
            break;
        transform(var.begin(), var.end(), var.begin(), ::tolower);
        ignores.insert(var);
    }

    // input titles
    set<string> keyword_set;
    string var;
    while (cin >> var) {
        vector<string> title;

        while (true) {
            transform(var.begin(), var.end(), var.begin(), ::tolower);
            title.push_back(var);

            if (ignores.find(var) == ignores.end()
                and keyword_set.find(var) == keyword_set.end()) {
                keyword.push_back(var);
                keyword_set.insert(var);
            }

            if (cin.get() == '\n')
                break;

            cin >> var;
        }

        titles.push_back(title);
    }
    sort(keyword.begin(), keyword.end());
}

void testOutput() {
    // test output
    cout << "\t\ttitles" << endl;
    for (int i = 0; i < titles.size(); i++) {
        for (int j = 0; j < titles[i].size(); j++)
            cout << titles[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // test output
    cout << "\t\tkeyword" << endl;
    for (int i = 0; i < keyword.size(); i++)
        cout << keyword[i] << endl;
    cout << endl;
}


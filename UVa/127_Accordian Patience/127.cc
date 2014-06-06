#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct {
    char rank;
    char suit;
} Card;

bool match(Card a, Card b);

int main() {

    ios::sync_with_stdio(false);

    char rank, suit;
    while (cin >> rank) {
        if (rank == '#')
            break;
        cin.putback(rank);

        vector< stack<Card> > v(52);        
        for (int i = 0; i < 52; i++) {
            cin >> rank >> suit;
            Card card = {rank, suit};
            v[i].push(card);
        }

        int n = 52;
        for (int i = 0; i < n; i++) {
            if (i >= 0 and v[i].empty()) {
                for (int j = i; j < n - 1; j++)
                    v[j] = v[j+1];
                n--;
                i--;
                continue;
            }
            if (i - 3 >= 0 and match(v[i].top(), v[i-3].top())) {
                v[i-3].push(v[i].top());
                v[i].pop();
                i -= 4;
                continue;
            }
            if (i - 1 >= 0 and match(v[i].top(), v[i-1].top())) {
                v[i-1].push(v[i].top());
                v[i].pop();
                i -= 2;
                continue;
            }
        }

        cout << n << " pile" << (n > 1 ? "s" : "") << " remaining:";
        for (int i = 0; i < n; i++)
            cout << " " << v[i].size();
        cout << endl;

    }

    return 0;
}

bool match(Card a, Card b) {
    return a.suit == b.suit or a.rank == b.rank;
}

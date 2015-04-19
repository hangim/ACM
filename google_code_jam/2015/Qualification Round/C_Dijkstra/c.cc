// just sloved small input

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int sgn;
    char c;
    Node() = default;
    Node(int _sgn, char _c) : sgn(_sgn), c(_c) {}
    Node(char _c) : Node(1, _c) {}
    bool operator == (const Node &o) const {
        return sgn == o.sgn and c == o.c;
    }
    Node operator * (const Node &o) const {
        switch (c) {
        case '1':
            switch (o.c) {
                case '1': return Node(sgn * o.sgn, '1');
                case 'i': return Node(sgn * o.sgn, 'i');
                case 'j': return Node(sgn * o.sgn, 'j');
                case 'k': return Node(sgn * o.sgn, 'k');
            }
        case 'i':
            switch (o.c) {
                case '1': return Node(sgn * o.sgn, 'i');
                case 'i': return Node(sgn * o.sgn * -1, '1');
                case 'j': return Node(sgn * o.sgn, 'k');
                case 'k': return Node(sgn * o.sgn * -1, 'j');
            }
        case 'j':
            switch (o.c) {
                case '1': return Node(sgn * o.sgn, 'j');
                case 'i': return Node(sgn * o.sgn * -1, 'k');
                case 'j': return Node(sgn * o.sgn * -1, '1');
                case 'k': return Node(sgn * o.sgn, 'i');
            }
        case 'k':
            switch (o.c) {
                case '1': return Node(sgn * o.sgn, 'k');
                case 'i': return Node(sgn * o.sgn, 'j');
                case 'j': return Node(sgn * o.sgn * -1, 'i');
                case 'k': return Node(sgn * o.sgn * -1, '1');
            }
        }
    }
};

Node S[10010];
Node S1[10010], S2[10010];

bool judge(int len) {
    for (int i = 1; i != len; ++i) {
        if (S1[i-1] == Node('i')) {
            Node c2 = S[i];
            for (int j = i + 1; j != len; ++j) {
                if (c2 == Node('j')) {
                    if (S2[j] == Node('k'))
                        return true;
                }
                c2 = c2 * S[j];
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int L, X;
        cin >> L >> X;
        string str;
        cin >> str;
        int Len = L * X;
        for (int i = 0; i != Len; ++i)
            S[i] = Node(str[i % L]);

        S1[0] = S[0], S2[Len-1] = S[Len-1];
        for (int i = 1; i != Len; ++i)
            S1[i] = S1[i-1] * S[i];
        for (int i = Len - 2; i >= 0; --i)
            S2[i] = S[i] * S2[i+1];

        cout << "Case #" << cases << ": "
             << (judge(Len) ? "YES" : "NO") << endl;
    }
    return 0;
}


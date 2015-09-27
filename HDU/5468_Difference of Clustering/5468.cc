#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;
int c0[maxn + 10], c1[maxn + 10];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        map<int, vector<int> > oldmv;
        map<int, vector<int> > newmv;

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &c0[i], &c1[i]);
            oldmv[c0[i]].push_back(i);
            newmv[c1[i]].push_back(i);
        }
        int splits = 0, merges = 0, dont = 0;

        // splits
        vector<int> tobe_delete;
        for (auto it : oldmv) {
            set<int> s; // 新的分组ID
            for (auto it1 : it.second)
                s.insert(c1[it1]);
            
            if (s.size() == 1) // merge or 1:1
                continue;

            int cnt = 0;
            for (auto it2 : s)
                cnt += newmv[it2].size();

            if (cnt == it.second.size()) {
                splits++;
                tobe_delete.push_back(it.first); // 删除旧
                for (auto it2 : s)
                    newmv[it2].clear();
            }
        }
        for (auto it : tobe_delete)
            oldmv[it].clear();
        tobe_delete.clear();



        // merges
        for (auto it : newmv) {
            if (it.second.size() == 0)
                continue;

            set<int> s; // 旧的分组ID
            for (auto it1 : it.second)
                s.insert(c0[it1]);

            if (s.size() == 1) // splits or 1:1
                continue;

            int cnt = 0;
            for (auto it2 : s)
                cnt += oldmv[it2].size();

            if (cnt == it.second.size()) {
                merges++;
                tobe_delete.push_back(it.first); // 删除新
                for (auto it2 : s) // 删除旧
                    oldmv[it2].clear();
            }
        }
        for (auto it : tobe_delete)
            newmv[it].clear();
        tobe_delete.clear();



        // 1:1
        for (auto it : oldmv) {
            set<int> s;
            for (auto it1 : it.second)
                s.insert(c1[it1]);
            if (s.size() == 1 and it.second.size() == newmv[*s.begin()].size()) {
               dont++; 
            }
        }

        printf("Case #%d: %d %d %d\n", cs, splits, merges, dont);
    }

    return 0;
}


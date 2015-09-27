#include <bits/stdc++.h>

using namespace std;

bool buf[64];

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; cs++) {
        long long d;
        int s1, s2, cnt = 0;
        scanf("%lld %d %d", &d, &s1, &s2);
        for (int i = 0; i < 35; ++i) {
            if (d & (1LL << i)) {
                buf[i] = 1;
                cnt++;
            } else {
                buf[i] = 0;
            }
        }

//        cout << cnt << endl;
//        for (int i = 0; i < 35; ++i)
//            cout << buf[i] << " ";
//        cout << endl;
        
        int index = -1;
        bool flag = cnt != s2;
        //for (int i = 0; i < 31; ++i) {
        for (int i = 0; i < 35; ++i) {
            if (buf[i] == 0) {
                //if (flag == false) { // 跳过第一个
                //if (flag == false and i == 0) {
                if (flag == false) {
                    //flag = true;
                    buf[i] = 1;
                    cnt++;
                } else {
                    index = i;
                    buf[i] = 1;
                    cnt++;
                    break;
                }
            } else {
                flag = true;
            }
        }


//        for (int i = 0; i < 35; ++i)
//            cout << buf[i] << " ";
//        cout << endl;

        for (index = index - 1; index >= 0; index--) {
            if (cnt > s1 and buf[index]) {
                cnt--;
                buf[index] = 0;
            }
        }

//        for (int i = 0; i < 35; ++i)
//            cout << buf[i] << " ";
//        cout << endl;

        long long ans = 0;
        for (int i = 0; i < 35; ++i) {
            if (buf[i])
                ans |= (1LL << i);
        }
        
        printf("Case #%d: %lld\n", cs, ans);
    }
    return 0;
}


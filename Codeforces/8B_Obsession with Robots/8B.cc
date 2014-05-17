#include <iostream>
#include <string>

using namespace std;

int main() {

    int map[201][201]; 
    string str;
    cin >> str;
    int len = str.length();

    int x = 100, y = 100;
    map[x][y] = 1;
    
    bool flag = true;    

    for (int i = 0; flag and i < len; i++) {
        switch (str[i]) {
        case 'L':
            if (map[x-1][y])
                flag = false;
            else
                map[--x][y] = 1;
                if (map[x-1][y] or map[x][y+1] or map[x][y-1])
                    flag = false;
            break;

        case 'R':
            if (map[x+1][y])
                flag = false;
            else
                map[++x][y] = 1;
                if (map[x+1][y] or map[x][y+1] or map[x][y-1])
                    flag = false;
            break;

        case 'U':
            if (map[x][y-1])
                flag = false;
            else
                map[x][--y] = 1;
                if (map[x][y-1] or map[x-1][y] or map[x+1][y])
                    flag = false;
            break;

        case 'D':         
            if (map[x][y+1])
                flag = false;
            else
                map[x][++y] = 1;
                if (map[x][y+1] or map[x-1][y] or map[x+1][y])
                    flag = false;
            break;
        }
    }
    
    if (flag)
        cout << "OK" << endl;
    else
        cout << "BUG" << endl;
    
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int res = 1;
char map[51][51];

void check_max_value() {
    // 가로 계산
    for (int i = 0; i < n; i++) {
        int tmp = 1;
        
        for (int j = 0; j < n - 1; j++) {
            if (map[i][j] == map[i][j + 1]) tmp++;
            else tmp = 1;

            res = max(res, tmp);
        }
    }

    // 세로 계산
    for (int j = 0; j < n; j++) {
        int tmp = 1;

        for (int i = 0; i < n - 1; i++) {
            if (map[i][j] == map[i + 1][j]) tmp++;
            else tmp = 1;

            res = max(res, tmp);
        }
    }
}

int main() {
    cin >> n;

    // get inputs
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            map[i][j] = s[j];
        }
    }

    // 가로로 교환
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(map[i][j], map[i][j + 1]);
            check_max_value();
            swap(map[i][j], map[i][j + 1]);
        }
    }

    // 세로로 교환
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            swap(map[i][j], map[i + 1][j]);
            check_max_value();
            swap(map[i][j], map[i + 1][j]);
        }
    }

    cout << res << "\n";

    return 0;
}
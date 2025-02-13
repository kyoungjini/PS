#include <iostream>
using namespace std;

int n;
int res = 0;
int house[17][17];

void dfs (int x2, int y2, int status) {

    if (x2 == n && y2 == n) {
        res++;
        return;
    }

    // 대각선으로 이동
    if ((1 <= x2 + 1) && (x2 + 1 <= n) && (1 <= y2 + 1) && (y2 + 1 <= n)) {
        if (!house[x2][y2 + 1] && !house[x2 + 1][y2] && !house[x2 + 1][y2 + 1]) {
            dfs(x2 + 1, y2 + 1, 2);
        }
    }

    if (status == 1) {          // 가로
        // 오른쪽으로 이동
        if ((1 <= y2 + 1) && (y2 + 1 <= n)) {
            if (!house[x2][y2 + 1]) {
                dfs(x2, y2 + 1, 1);
            }
        } 
    }
    else if (status == 2) {     // 대각선
        // 오른쪽으로 이동
        if ((1 <= y2 + 1) && (y2 + 1 <= n)) {
            if (!house[x2][y2 + 1]) {
                dfs(x2, y2 + 1, 1);
            }
        } 

        // 아래로 이동
        if ((1 <= x2 + 1) && (x2 + 1 <= n)) {
            if (!house[x2 + 1][y2]) {
                dfs(x2 + 1, y2, 3);
            }
        }
    }
    else if (status == 3) {     // 세로
        // 아래로 이동
        if ((1 <= x2 + 1) && (x2 + 1 <= n)) {
            if (!house[x2 + 1][y2]) {
                dfs(x2 + 1, y2, 3);
            }
        }
    }
}

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> house[i][j];
        }
    }

    // status : 가로 1. 대각선 2. 세로 3
    dfs(1, 2, 1);

    cout << res << "\n";

    return 0;
}
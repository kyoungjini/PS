#include <iostream>
using namespace std;

int n, m, res;
int arr[501][501];
int dp[501][501];

// up right left down
int x_dir[4] = {-1, 0, 0, 1};
int y_dir[4] = {0, 1, -1, 0};

int dfs(int x, int y) {

    if (x == m - 1 && y == n - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

        if (arr[x][y] > arr[next_x][next_y]) {
            dp[x][y] += dfs(next_x, next_y);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    res = dfs(0, 0);

    cout << res << "\n";

    return 0;
}

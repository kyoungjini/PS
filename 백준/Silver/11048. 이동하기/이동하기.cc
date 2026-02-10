#include <iostream>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int x_dir[3] = {1, 0, 1};
int y_dir[3] = {0, 1, 1};

void DP(int x, int y) {

    for (int i = 0; i < 3; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;

        dp[next_x][next_y] = max(dp[next_x][next_y], arr[next_x][next_y] + dp[x][y]);
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            DP(i, j);
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}
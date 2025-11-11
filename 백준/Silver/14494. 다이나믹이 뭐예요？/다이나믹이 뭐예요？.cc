#include <iostream>
using namespace std;

long long dp[1000][1000];
long long val = 1e9 + 7;
long long x_dir[3] = {0, 1, 1};
long long y_dir[3] = {1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 3; k++) {
                long long next_x = i + x_dir[k];
                long long next_y = j + y_dir[k];

                if (next_x < n && next_y < m) dp[next_x][next_y] = (dp[next_x][next_y] + dp[i][j]) % val;
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}
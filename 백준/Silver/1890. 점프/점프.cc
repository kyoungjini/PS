#include <iostream>
using namespace std;

int n;
int graph[100][100];
long long dp[100][100] = {0, };

void jump(int start_x, int start_y) {

    dp[start_x][start_y]++;

    int next_x, next_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0 || graph[i][j] == 0) continue;

            next_x = i + graph[i][j];
            next_y = j + graph[i][j];

            if (next_x < n) dp[next_x][j] += dp[i][j];
            if (next_y < n) dp[i][next_y] += dp[i][j]; 
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    jump(0, 0);

    cout << dp[n - 1][n - 1] << "\n";

    return 0;
}
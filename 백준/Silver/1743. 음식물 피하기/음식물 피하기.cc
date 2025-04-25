#include <iostream>
using namespace std;

int n, m;
int res = 0;
int cnt = 0;
int graph[101][101];
bool visited[101][101];

// left right up down
int x_dir[4] = {0, 0, -1, 1};
int y_dir[4] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    
    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) continue;

        if (graph[next_x][next_y] == 1 && !visited[next_x][next_y]) {
            dfs(next_x, next_y);
        }
    }
}

int main() {
    int k;
    cin >> n >> m >> k;

    // get inputs
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        graph[r][c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                cnt = 0;
                dfs(i, j);
                res = max(res, cnt);
            }
        }
    }

    cout << res << "\n";

    return 0;
}
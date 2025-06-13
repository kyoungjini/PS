#include <iostream>
using namespace std;

int n, m;
int num = 0;
int max_val = 0;
int tmp_val = 0;
int graph[500][500];
bool visited[500][500];

// up down left right
int x_dir[4] = { 0, 0, -1, 1 };
int y_dir[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
    bool flag = false;

    visited[x][y] = true;
    tmp_val++;

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
        if (graph[next_x][next_y] == 1 && !visited[next_x][next_y]) {
            dfs(next_x, next_y);
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                tmp_val = 0;
                num++;
                dfs(i, j);
                max_val = max(max_val, tmp_val);
            }
        }
    }

    cout << num << "\n" << max_val << "\n";

    return 0;
}
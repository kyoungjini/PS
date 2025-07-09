#include <iostream>
using namespace std;

int n, m;
char graph[100][100];
bool visited[100][100];
int my_power = 0;
int enemy_power = 0;
int tmp_num;

// up down left right
int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
    char current_color = graph[x][y];

    tmp_num++;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
        if (visited[next_x][next_y] || graph[next_x][next_y] != current_color) continue;

        dfs(next_x, next_y);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < n; j++) {
            graph[i][j] = tmp[j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                tmp_num = 0;
                dfs(i, j);
                graph[i][j] == 'W' ? (my_power += tmp_num * tmp_num) : (enemy_power += tmp_num * tmp_num);
            }
        }
    }

    cout << my_power << " " << enemy_power << "\n";

    return 0;
}
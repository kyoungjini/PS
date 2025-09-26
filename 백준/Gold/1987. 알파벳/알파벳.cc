#include <iostream>
using namespace std;

int r, c;
int res = 0;
char graph[21][21];
bool alphabet[28];
bool visited[21][21];

// up down left right
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt) {

    res = max(res, cnt);

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) continue;

        if (!alphabet[graph[next_x][next_y] - 'A'] && !visited[next_x][next_y]) {
            alphabet[graph[next_x][next_y] - 'A'] = true;
            visited[next_x][next_y] = true;

            dfs(next_x, next_y, cnt + 1);

            alphabet[graph[next_x][next_y] - 'A'] = false;
            visited[next_x][next_y] = false;
        }
    }
}

int main() {
    
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < c; j++) {
            graph[i][j] = s[j];
        }
    }

    alphabet[graph[0][0] - 'A'] = true;
    visited[0][0] = true;
    dfs(0, 0, 1);

    cout << res << "\n";

    return 0;
}
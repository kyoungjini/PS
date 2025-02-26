#include <iostream>
#include <queue>
using namespace std;

int n, m;
int res = 0;
int arr[3001][3001];
bool visited[3001][3001];

// 상하좌우
int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

bool bfs(int start_x, int start_y) {
    queue<pair<pair<int, int>, int>> q;

    q.push(make_pair(make_pair(start_x, start_y), 0));
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + x_dir[i];
            int next_y = y + y_dir[i];

            if (0 <= next_x && next_x < n && 0 <= next_y && next_y < m) {
                if (!visited[next_x][next_y]) {
                    if (arr[next_x][next_y] == 0) {
                        visited[next_x][next_y] = true;
                        q.push(make_pair(make_pair(next_x, next_y), cnt + 1));
                    }
                    else if (arr[next_x][next_y] > 2) {
                        res = cnt + 1;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
            if (arr[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }

    bool flag = bfs(x, y);

    if (flag) cout << "TAK\n" << res << "\n";
    else cout << "NIE" << "\n";

    return 0;
}
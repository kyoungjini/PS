#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n, k;
bool colored[101][101];
bool visited[101][101];

vector<int> v;

// up down left right
int x_dir[4] = {0, 0, -1, 1};
int y_dir[4] = {1, -1, 0, 0};

int dfs(int x, int y, int cnt) {

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int next_x = x + x_dir[i];
        int next_y = y + y_dir[i];

        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;

        if (!colored[next_x][next_y] && !visited[next_x][next_y]) {
            cnt += dfs(next_x, next_y, 1);
        }
    }

    return cnt;
}

int main() {
    
    cin >> m >> n >> k;

    // get inputs
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) {
            for (int t = x1; t < x2; t++) {
                colored[t][j] = true;
            }
        }
    }

    // dfs
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!colored[j][i] && !visited[j][i]) {
                int res = dfs(j, i, 1);
                v.push_back(res);
            }    
        }
    }

    // print the result
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";

    return 0;
}
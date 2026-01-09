#include <iostream>
#include <queue>
using namespace std;

int n, res = 0;
bool graph[501][501];
bool visited[501];

void bfs(int x) {
    queue<pair<int, int>> q;

    visited[x] = true;
    q.push({x, 0});

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_depth = q.front().second;
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (graph[cur_x][i] && cur_depth < 2 && !visited[i]) {
                visited[i] = true;
                q.push({i, cur_depth + 1});
                res++;
            }
        }
    }
}

int main() {
    int m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    bfs(1);

    cout << res << "\n";

    return 0;
}
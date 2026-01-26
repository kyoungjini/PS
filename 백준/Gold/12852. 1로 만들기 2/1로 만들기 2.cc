#include <iostream>
#include <queue>
using namespace std;

int n;
int parent[1000001];
bool visited[1000001];

int bfs (int start_x) {
    queue<pair<int, int>> q;

    visited[start_x] = true;
    q.push({start_x, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // case 1
        if (x % 3 == 0 && !visited[x / 3]) {
            visited[x / 3] = true;
            q.push({x / 3, cnt + 1});
            parent[x / 3] = x;

            if (x / 3 == 1) return cnt + 1;
        }
        // case 2
        if (x % 2 == 0 && !visited[x / 2]) {
            visited[x / 2] = true;
            q.push({x / 2, cnt + 1});
            parent[x / 2] = x;

            if (x / 2 == 1) return cnt + 1;
        }
        // case 3
        if (x - 1 > 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push({x - 1, cnt + 1});
            parent[x - 1] = x;

            if (x - 1 == 1) return cnt + 1;
        }
    }

    return 0;
}

void print_parent(int x) {
    if (x < n) print_parent(parent[x]);
    cout << x << " ";
    return;
}

int main() {
    int res;
    cin >> n;

    res = bfs(n);
    cout << res << "\n";

    print_parent(1);
    cout << "\n";

    return 0;
}

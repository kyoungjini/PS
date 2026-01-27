#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int n, k;
int parent[100001];
bool visited[100001];

int bfs(int start_x) {
    queue<pair<int, int>> q;

    visited[start_x] = true;
    q.push({start_x, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // target
        if (x == k) return cnt;

        // case 1
        if (x + 1 <= MAX && !visited[x + 1]) {
            visited[x + 1] = true;
            parent[x + 1] = x;
            q.push({x + 1, cnt + 1});
        }
        // case 2
        if (x - 1 >= 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            parent[x - 1] = x;
            q.push({x - 1, cnt + 1});
        }
        // case 3
        if (x * 2 <= MAX && !visited[x * 2]) {
            visited[x * 2] = true;
            parent[x * 2] = x;
            q.push({x * 2, cnt + 1});
        }
    }  

    return 0;
}

void print_parent(int x) {
    if (x != n) print_parent(parent[x]);
    cout << x << " ";
    return;
}

int main() {
    int res;

    cin >> n >> k;

    res = bfs(n);
    cout << res << "\n";

    print_parent(k);
    cout << "\n";

    return 0;
}
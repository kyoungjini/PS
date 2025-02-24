#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000
int a, b, n, m;
bool visited[MAX + 1];

int bfs() {
    int dir[8] = {1, -1, a, -a, b, -b , a, b};
    queue<pair<int, int>> q;

    visited[n] = true;
    q.push(make_pair(n, 0));

    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == m) return cnt;

        for (int i = 0; i < 8; i++) {
            int next_x;

            if (i < 6) next_x = x + dir[i];
            else next_x = x * dir[i];
            
            if (0 <= next_x && next_x <= MAX && !visited[next_x]) {
                visited[next_x] = true;
                q.push(make_pair(next_x, cnt + 1));
            }
        }
    }

    return 0;
}

int main() {
    cin >> a >> b >> n >> m;

    cout << bfs() << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[10001];
bool visited[10001];
int end_node, res = 0;

void dfs(int x, int dist) {

    visited[x] = true;
    
    if (res < dist) {
        res = dist;
        end_node = x;
    }

    for (int i = 0; i < graph[x].size(); i++) {
        int next_x = graph[x][i].first;
        int next_dist = dist + graph[x][i].second;

        if (!visited[next_x]) dfs(next_x, next_dist);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(end_node, 0);

    cout << res << "\n";

    return 0;
}
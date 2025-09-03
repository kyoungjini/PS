#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int INF = 98765432;
int n, e;
vector<pair<int, int>> graph[801];
int dist[801];

void bfs(int start_node) {
    memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start_node});
    dist[start_node] = 0;

    while(!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;

            if (next_dist < dist[next_node]) {
                pq.push({next_dist, next_node});
                dist[next_node] = next_dist;
            }
        }
    }
}

int main() {
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int u, v;
    cin >> u >> v;

    bfs(1);
    int dist_1_to_u = dist[u];
    int dist_1_to_v = dist[v];

    bfs(u);
    int dist_u_to_v = dist[v];
    int dist_u_to_n = dist[n];

    bfs(v);
    int dist_v_to_u = dist[u];
    int dist_v_to_n = dist[n];

    int res;
    res = min(INF, dist_1_to_u + dist_u_to_v + dist_v_to_n);
    res = min(res, dist_1_to_v + dist_v_to_u + dist_u_to_n);

    cout << (res == INF ? -1 : res) << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int INF = 98765432;
vector<pair<int, int>> graph[20001];
int dist[20001];

void bfs(int start_node) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dist, INF, sizeof(dist));

    dist[start_node] = 0;
    pq.push({0, start_node});

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if (dist[cur_node] < cur_dist) continue;

        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second + cur_dist;

            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
}

int main() {
    int v, e, k;
    cin >> v >> e >> k;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
    }

    bfs(k);

    for (int i = 1; i <= v; i++) {
        if (i == k) {
            cout << "0\n";
        } else if (dist[i] >= INF) {
            cout << "INF\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
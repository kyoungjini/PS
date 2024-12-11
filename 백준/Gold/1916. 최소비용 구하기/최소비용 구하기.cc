#define _CRT_SECURE_NOWARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 1e9
using namespace std;

vector<pair<int, int>> v[1001];
int dist[1001];

void dijkstra(int start_city) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// push cost & node idx
	pq.push(make_pair(0, start_city));
	dist[start_city] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int city = pq.top().second;
		pq.pop();

		// cannot be the minimum cost -> skip
		if (cost > dist[city]) continue;

		for (int i = 0; i < v[city].size(); i++) {
			int next_city = v[city][i].first;
			int next_cost = cost + v[city][i].second;

			// less cost -> update
			if (next_cost < dist[next_city]) {
				pq.push(make_pair(next_cost, next_city));
				dist[next_city] = next_cost;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	// initialize 'dist'
	fill(dist, dist + 1001, INF);

	// bus info
	for (int i = 0; i < m; i++) {
		int city1, city2, cost;
		cin >> city1 >> city2 >> cost;
		v[city1].push_back(make_pair(city2, cost));
	}

	// target info
	int start_city, end_city;
	cin >> start_city >> end_city;

	dijkstra(start_city);

	cout << dist[end_city] << "\n";

	return 0;
}
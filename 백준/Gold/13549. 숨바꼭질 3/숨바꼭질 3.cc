#define _CRT_SECURE_NOWARNINGS
#include <iostream>
#include <queue>
using namespace std;

#define MAX 200000
int cost[300000];

void dijkstra(int start_pos) {
	// save { time, position } in pq
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	cost[start_pos] = 0;
	pq.push(make_pair(0, start_pos));

	while (!pq.empty()) {
		int time = pq.top().first;
		int pos = pq.top().second;
		pq.pop();

		if (time > cost[pos]) continue;

		int next_time, next_pos;

		// case 1
		if (pos - 1 >= 0) {
			next_time = time + 1;
			next_pos = pos - 1;

			if (next_time < cost[next_pos]) {
				cost[next_pos] = next_time;
				pq.push(make_pair(next_time, next_pos));
			}
		}

		// case 2
		if (pos + 1 < MAX) {
			next_time = time + 1;
			next_pos = pos + 1;

			if (next_time < cost[next_pos]) {
				cost[next_pos] = next_time;
				pq.push(make_pair(next_time, next_pos));
			}
		}

		// case 3
		if (pos * 2 < MAX) {
			next_time = time;
			next_pos = pos * 2;

			if (next_time < cost[next_pos]) {
				cost[next_pos] = next_time;
				pq.push(make_pair(next_time, next_pos));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	// initialize minimum cost array
	fill(cost, cost + 300000, MAX);

	dijkstra(n);

	cout << cost[k] << "\n";

	return 0;
}
#define _CRT_SECURE_NOWARNINGS
#include <iostream>
using namespace std;

int graph[1025][1025];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// save partial sum in 'graph' array
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			int k;
			cin >> k;
			tmp += k;
			graph[i][j] = tmp;
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int res = 0;
		for (int j = x1; j <= x2; j++) {
			res += (graph[j][y2] - graph[j][y1 - 1]);
		}

		cout << res << "\n";
	}

	return 0;
}
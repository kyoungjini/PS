#define _CRT_SECURE_NOWARNINGS
#include <iostream>
using namespace std;

int graph[1025][1025];
int dp[1025][1025];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	// get inputs & complete 'graph', 'dp' array
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + graph[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int res;
		res = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		
		cout << res << "\n";
	}

	return 0;
}
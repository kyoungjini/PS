#define _CRT_SECURE_NOWARNINGS
#include <iostream>
using namespace std;

int graph[2][100010];
int dp[2][100010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		// get inputs
		int n;
		cin >> n;

		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> graph[j][k];
			}
		}

		// initialize before dp
		dp[0][1] = graph[0][1];
		dp[1][1] = graph[1][1];

		// dp
		int tmp1, tmp2;
		for (int j = 2; j <= n; j++) {
			// first row element
			tmp1 = dp[1][j - 1] + graph[0][j];
			tmp2 = dp[1][j - 2] + graph[0][j];
			dp[0][j] = max(tmp1, tmp2);

			// second row element
			tmp1 = dp[0][j - 1] + graph[1][j];
			tmp2 = dp[0][j - 2] + graph[1][j];
			dp[1][j] = max(tmp1, tmp2);
		}

		// print the result
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}

	return 0;
}
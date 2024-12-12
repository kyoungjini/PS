#define _CRT_SECURE_NOWARNINGS
#include <iostream>
using namespace std;

int dp[4][3]; // prev min xyz , cur min xyz, prev max xyz, cur max xyz

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	// first line
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	dp[2][0] = dp[0][0];
	dp[2][1] = dp[0][1];
	dp[2][2] = dp[0][2];
	
	for (int i = 1; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		// update cur values
		dp[1][0] = x + min(dp[0][0], dp[0][1]);
		dp[1][1] = y + min(min(dp[0][0], dp[0][1]), dp[0][2]);
		dp[1][2] = z + min(dp[0][1], dp[0][2]);

		dp[3][0] = x + max(dp[2][0], dp[2][1]);
		dp[3][1] = y + max(max(dp[2][0], dp[2][1]), dp[2][2]);
		dp[3][2] = z + max(dp[2][1], dp[2][2]);

		// update prev values
		for (int j = 0; j < 3; j++) {
			dp[0][j] = dp[1][j];
			dp[2][j] = dp[3][j];
		}
	}

	int res_min, res_max;
	res_min = min(min(dp[0][0],dp[0][1]), dp[0][2]);
	res_max = max(max(dp[2][0], dp[2][1]), dp[2][2]);

	cout << res_max << " " << res_min << "\n";

	return 0;
}
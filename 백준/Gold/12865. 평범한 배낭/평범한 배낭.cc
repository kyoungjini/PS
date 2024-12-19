#define _CRT_SECURE_NOWARNINGS
#include <iostream>
using namespace std;

int n, k;
int bag[101][2];
int max_value[101][100001];

void dp() {
	int w, v;

	for (int i = 1; i <= n; i++) {
		w = bag[i][0];
		v = bag[i][1];

		for (int j = 1; j <= k; j++) {
			if (w > j) {
				max_value[i][j] = max_value[i - 1][j];
			}
			else {
				max_value[i][j] = max(max_value[i - 1][j], v + max_value[i - 1][j - w]);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	int left_w = k;

	for (int i = 1; i <= n; i++) {
		// weight and value
		cin >> bag[i][0] >> bag[i][1];
	}

	dp();

	cout << max_value[n][k] << "\n";

	return 0;
}
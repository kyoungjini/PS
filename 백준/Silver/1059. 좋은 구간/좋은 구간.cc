#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int v_size;
	vector<int> v;
	int n;

	// get inputs
	cin >> v_size;
	v.push_back(0);
	for (int i = 0; i < v_size; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> n;

	sort(v.begin(), v.end());

	int min_range, max_range;

	// decide the range
	for (int i = 1; i <= v_size; i++) {
		// corner case
		if (v[i] == n) {
			cout << 0 << "\n";
			return 0;
		}

		if (n < v[i]) {
			min_range = v[i - 1] + 1;
			max_range = v[i] - 1;
			break;
		}
	}
	
	int res = 0;
	res += (n - min_range) * (max_range - n + 1);
	res += max_range - n;

	cout << res << "\n";

	return 0;
}
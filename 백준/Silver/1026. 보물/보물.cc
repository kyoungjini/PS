#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int res = 0;
	vector<int> a;
	vector<int> b;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}

	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		res += a[i] * b[i];
	}

	cout << res << "\n";

	return 0;
}
#include <iostream>
using namespace std;

int main() {

	long long n, m;
	cin >> n >> m;

	if (n >= m) cout << "0\n";
	else {
		long long n_f = 1;

		for (int i = 2; i <= n; i++) {
			n_f *= i;
			n_f %= m;
		}

		cout << n_f << "\n";
	}

	return 0;
}
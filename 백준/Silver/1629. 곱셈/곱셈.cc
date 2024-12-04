#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long a, b, c;

long long fpow(long long k, long long n) {

	if (n == 0) return 1;

	long long x = fpow(k, n / 2);

	x = x * x % c;

	if (n % 2 == 0) {
		// n이 짝수일 때
		return x;
	}
	else {
		// n이 홀수일 때
		return x * k % c;
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	long long res = fpow(a, b);

	cout << res << "\n";

	return 0;
}
#include <iostream>
#include <set>
using namespace std;

set<string> s;

int main() {

	int n;
	char c;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}

	int res = 0;
	if (c == 'Y') {
		res = s.size();
	}
	else if (c == 'F') {
		res = s.size() / 2;
	}
	else if (c == 'O') {
		res = s.size() / 3;
	}

	cout << res << "\n";

	return 0;
}
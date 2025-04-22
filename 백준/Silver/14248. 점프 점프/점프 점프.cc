#include <iostream>
#include <vector>
using namespace std;

int n;
int res = 0;
vector<int> v;
bool visited[100000];

void dfs(int x) {
	visited[x] = true;
	res++;

	int next_x_1 = x - v[x];
	int next_x_2 = x + v[x];

	if (0 <= next_x_1 && next_x_1 < n && !visited[next_x_1]) {
		dfs(next_x_1);
	}

	if (0 <= next_x_2 && next_x_2 < n && !visited[next_x_2]) {
		dfs(next_x_2);
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int s;
	cin >> s;

	dfs(s - 1);

	cout << res << "\n";

	return 0;
}
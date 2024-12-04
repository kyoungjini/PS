#define _CRT_SECURE_NOWARNINGS
#include <iostream>
#include <queue>
using namespace std;

int graph[27][2];
bool visited[27];

queue<char> pre_q;
queue<char> in_q;
queue<char> post_q;

void dfs(int int_node) {

	visited[int_node] = true;
	pre_q.push(int_node + 'A');

	// search left child
	int lnode = graph[int_node][0];
	if (lnode >= 0 && !visited[lnode]) {
		visited[lnode] = true;
		dfs(lnode);
	}

	in_q.push(int_node + 'A');

	// search right child
	int rnode = graph[int_node][1];
	if (rnode >= 0 && !visited[rnode]) {
		visited[rnode] = true;
		dfs(rnode);
	}

	post_q.push(int_node + 'A');
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// get inputs
	int n;
	cin >> n;

	char x, y, z;
	int int_x = 0;
	int int_y, int_z;

	for (int i = 0; i < n; i++) {
		// parent - left child - right child
		cin >> x >> y >> z;
		
		// char to int
		int_x = x - 'A';
		int_y = y - 'A';
		int_z = z - 'A';
		
		if (int_y > 0) {
			graph[int_x][0] = int_y;
		}

		if (int_z > 0) {
			graph[int_x][1] = int_z;
		}
	}

	dfs(0);	// int of 'A'

	// print the result
	for (int i = 0; i < n; i++) {
		char x = pre_q.front();
		pre_q.pop();
		cout << x;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		char x = in_q.front();
		in_q.pop();
		cout << x;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		char x = post_q.front();
		post_q.pop();
		cout << x;
	}
	cout << "\n";


	return 0;
}
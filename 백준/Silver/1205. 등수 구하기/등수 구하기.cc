#include <iostream>
using namespace std;

int main() {

	int n, new_score, p;
	int new_rank = 1;
	int new_idx = 1;
	int arr[52];

	// get inputs
	cin >> n >> new_score >> p;
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// decide rank of new_score
	for (int i = 1; i <= n; i++) {
		if (new_score < arr[i]) {
			new_rank++;
		}
		else if (new_score > arr[i]) {
			break;
		}
		
		new_idx++;
	}

	if (new_idx > p) new_rank = -1;
	cout << new_rank << "\n";

	return 0;
}
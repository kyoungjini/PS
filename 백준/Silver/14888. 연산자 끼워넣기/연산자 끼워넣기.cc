#include <iostream>
using namespace std;

int n;
int num_arr[12];
int op_arr[4];

int min_res = 1e9;
int max_res = -1e9;

void dfs(int x, int idx) {

    if (idx == n) {         // end
        min_res = min(min_res, x);
        max_res = max(max_res, x);
        return;
    }

    int y = num_arr[idx];
    int res;

    for (int i = 0; i < 4; i++) {
        if (!op_arr[i]) continue;
        
        op_arr[i]--;

        if (i == 0) {       // plus
            res = x + y;
        }
        else if (i == 1) {  // minus
            res = x - y;
        }
        else if (i == 2) {  // multiply
            res = x * y;
        }
        else {              // divide
            if (x >= 0) res = x / y;
            else res = -(-x / y);
        }

        dfs(res, idx + 1);
        op_arr[i]++;
    }
}

int main() {
    // get inputs
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num_arr[i];
    for (int i = 0; i < 4; i++) cin >> op_arr[i];

    dfs(num_arr[0], 1);

    cout << max_res << "\n" << min_res << "\n";

    return 0;
}
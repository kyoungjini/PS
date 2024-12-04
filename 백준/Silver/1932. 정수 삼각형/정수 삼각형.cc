#define _CRT_SECURE_NOWARNINGS 
#include <iostream>
using namespace std;

int dp[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // get input
            int x;
            cin >> x;

            if (i == 0 && j == 0) {     // case 1 - first element
                dp[0][0] = x;
            }
            else if (j == 0) {          // case 2 - left side element
                dp[i][j] = x + dp[i - 1][j];
            }
            else if (j == i) {          // case 3 - right side element
                dp[i][j] = x + dp[i - 1][j - 1];
            }
            else {                      // case 4 - others
                dp[i][j] = x + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, dp[n - 1][i]);
    }

    cout << res << "\n";

    return 0;
}
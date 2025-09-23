#include <iostream>
#include <vector>
using namespace std;

int INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> dp(k + 1, INF);

    // initialize
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        dp[value] = 1;
    }

    for (int i = 1; i <= k; i++) {
        if (dp[i] == 1) continue;

        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << (dp[k] >= INF ? -1 : dp[k]) << "\n";

    return 0;
}
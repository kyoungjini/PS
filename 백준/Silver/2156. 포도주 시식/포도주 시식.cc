#include <iostream>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        if (i == 1) dp[i] = arr[i];
        else if (i == 2) dp[i] = arr[i - 1] + arr[i];
        else dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
    }

    cout << dp[n] << "\n";

    return 0;
}
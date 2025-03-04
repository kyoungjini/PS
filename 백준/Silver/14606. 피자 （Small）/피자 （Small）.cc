#include <iostream>
using namespace std;

int main() {

    // dp
    int dp[11];

    dp[1] = 0;

    for (int i = 2; i <= 10; i++) {
        int half_i = i / 2;

        if (i % 2 == 0) {   // 짝수
            dp[i] = (half_i * half_i) + 2 * dp[half_i];
        }
        else {              // 홀수
            dp[i] = (half_i * (half_i + 1)) + dp[half_i] + dp[half_i + 1];

        }
    }

    int n;
    cin >> n;

    cout << dp[n] << "\n";

    return 0;
}
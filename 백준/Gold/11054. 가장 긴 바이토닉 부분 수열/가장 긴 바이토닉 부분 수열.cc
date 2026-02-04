#include <iostream>
using namespace std;

int n, res = 0;
int arr[1001];
int dp1[1001];
int dp2[1001];

int main() {
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }
    
    // calculate left side
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ((arr[j] < arr[i]) && (dp1[i] < dp1[j] + 1)) {
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    // calculate right side
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if ((arr[j] < arr[i]) && (dp2[i] < dp2[j] + 1)) {
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    // sum
    for (int i = 0; i < n; i++) {
        res = max(res, dp1[i] + dp2[i] - 1);
    }

    cout << res << "\n";

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001];
int dp[1001];
vector<int> v[1001];
vector<int> res;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        v[i].push_back(arr[i]);

        for (int j = 1; j < i; j++) {
            if ((arr[i] > arr[j]) && (dp[i] < dp[j] + 1)) {
                v[i].clear();
                v[i] = v[j];
                v[i].push_back(arr[i]);
                dp[i] = dp[j] + 1;
            }
        }

        if (v[i].size() > res.size()) res = v[i];
    }

    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << "\n";

    return 0;
}
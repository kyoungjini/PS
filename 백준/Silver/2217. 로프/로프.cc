#include <iostream>
#include <algorithm>
using namespace std;

int n, res = 0;
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    res = arr[0] * n;
    for (int i = 1; i < n; i++) {
        int tmp = arr[i] * (n - i);
        res = max(res, tmp);
    }

    cout << res << "\n";

    return 0;
}
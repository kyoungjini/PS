#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int start = 0;
    int end = n - 1;
    int res = 0;

    while (start < end) {
        if (v[start] + v[end] <= k) {
            res++; 
            start++;
        }

        end--;
    }

    cout << res << "\n";

    return 0;
}